
#include <avr/io.h> 
#include <stdlib.h>
#include "USBtoSerial.h"
#include <util/delay.h>
#include "TM1001A.h"
#include "motors.h"
#include "misc.h"
#include "pins.h"
#include "plate.h"


#define UM_PER_ROUND    1000  //micrometers per axis revolution
#define STEPS_PER_ROUND 24   //steps per axis revolution


int32_t steps_to_um (int32_t steps){
  return steps*UM_PER_ROUND/STEPS_PER_ROUND;
}

int32_t um_to_steps (int32_t um){
  return um*STEPS_PER_ROUND/UM_PER_ROUND;
}
  
void print_steps_in_mm(int32_t steps) {
  int32_t um = steps_to_um(steps);
  uint16_t predot = abs(um/1000);
  uint16_t postdot = abs(um%1000);
  uart_print_sign(steps);
  uart_print_number(predot,3);
  uart_putc('.');
  uart_print_number_wlzeros(postdot,3);
}


  
void pos_report(void){ 
    uart_puts("x_pos: ");
    print_steps_in_mm(get_plate_pos_x());
    uart_puts("  y_pos: ");
    print_steps_in_mm(get_plate_pos_y());
    uart_puts("\r\n");
}


typedef enum {POSITION, GOTO, MOVEREL, SETZERO} action_t;

void parse_command(void){
  
  static char cmdbuffer[32];
  static char numbuffer[16];
  static uint16_t predot = 0,postdot = 0;
  static uint8_t cmdPos, curCmdLen, num_start = 0, nums_found = 0;
  uint8_t axis=0;
  action_t action = POSITION;
  int8_t num_sign = 1;
  char byte;
  
  /* Load the next byte from the USART transmit buffer into the USART */
  
  uint16_t pop = uart_getc();
  if(!(pop == EMPTY)){ 
  
    byte = (char) pop;
    
    if (byte == '\r' || byte == '\n') {// end of command, evaluate cemmand!
      uart_puts("\r\n");
      cmdbuffer[cmdPos] = '\0'; // terminate new command string
      curCmdLen = cmdPos;
      cmdPos = 0;
      
      
      if (cmdbuffer[0] == 'g' || cmdbuffer[0] == 'G') { // goto command
        action = GOTO;
      } else if ( cmdbuffer[0] == 'm' || cmdbuffer[0] == 'M') {
        action = MOVEREL;
      } else if ( cmdbuffer[0] == 'z' || cmdbuffer[0] == 'Z' ) {
        action = SETZERO;
      } else {
        action = POSITION;
      }
      
      if (cmdbuffer[1] == 'x' || cmdbuffer[1] == 'X') {
        axis = X;
      } else if (cmdbuffer[1] == 'y' || cmdbuffer[1] == 'Y') {
        axis = Y;
      }
      
      // if you expect coordinate, parse number!
      if (action == GOTO || action == MOVEREL){

        predot = 0;
        postdot = 0;
        num_sign = 1;
        num_start = 0;
        nums_found = 0;
        
        for (uint8_t i=2; i<=curCmdLen; i++) {
           if ( num_start == 0 && cmdbuffer[i] == '-' ) { // if you find a minus before
            // you find a digit, it's a negative number
             num_sign = -1;
           }
           
           if ( cmdbuffer[i] >= 48 && cmdbuffer[i] <= 57 ){ // is it a number?
             if ( num_start == 0) { // this is the first digit in the string
               num_start = i;
             }
           } else { // no digit!
             if ( num_start != 0) { // digits have been found before
                strncpy(numbuffer,cmdbuffer+num_start,i-num_start); // copy number found to
                // numbuffer
                numbuffer[i-num_start] = '\0'; // make sure it's always a terminated string
                nums_found++;
                if(nums_found == 1) { // its the predot digits
                  predot = atoi(numbuffer);
                } else { // its the postdot digits
                  uint8_t postdotlen = i-num_start;
                  if (postdotlen < 3){ // if too small ,fill with zeros
                    for( uint8_t j = postdotlen; j <=2; j++) {
                      numbuffer[j] = '0';
                    }
                  }
                  // crop the number to three post dot digits
                  numbuffer[3] = '\0';
                  
                  postdot = atoi(numbuffer);
                }
                num_start = 0;
             }
           }
        }
        
      }
      
      int32_t steps = 0,dest=0;
      
      switch (action) {
        case GOTO:
          uart_puts("GOTO ");
          uart_putc(88+axis);// x or y
          uart_putc(' ');
          uart_print_sign(num_sign);
          uart_print_number(predot,3);
          uart_putc('.');
          uart_print_number_wlzeros(postdot,3);
          uart_puts("\r\n"); 
          
          dest = um_to_steps(num_sign*(((int32_t) predot) *1000 + ((int32_t) postdot)));
          
          if (axis == X) {
            set_target_plate_pos_x(dest);
          } else if (axis == Y) {
            set_target_plate_pos_y(dest);
          }
          
          break;
        case MOVEREL:
          uart_puts("MOVE ");
          uart_putc(88+axis);// x or y
          uart_putc(' ');
          uart_print_sign(num_sign);
          uart_print_number(predot,3);
          uart_putc('.');
          uart_print_number_wlzeros(postdot,3);
          uart_puts("\r\n"); 
          
          steps = um_to_steps(num_sign*(((int32_t) predot) *1000 + ((int32_t) postdot)));
          
          if (axis == X) {
            set_target_plate_pos_x(get_target_plate_pos_x()+steps);
          } else if (axis == Y) {
            set_target_plate_pos_y(get_target_plate_pos_y()+steps);
          }
          break;
          
        case SETZERO:
          set_plate_pos_x(0);
          set_plate_pos_y(0);
          set_target_plate_pos_x(0);
          set_target_plate_pos_y(0);
          pos_report();
          break;
          
        case POSITION:
          pos_report();
          break;
      }
      
      
    } else { // queue command
      if( cmdPos == 0 ){
        uart_puts("\r\n$ ");
      }
      
      if( byte == 8 ){ // backspace
        cmdPos--;
      } else {
        cmdbuffer[cmdPos++] = byte;
      }
      uart_putc(byte);
      

    }
  }
}



int main(void){
 
  init_motors();
  init_leds();
  init_sw();
  
  SetupHardware(); //initializes all USB stuff
  touchpad_init(); // you need to call this to setup the I/O pin!
  _delay_ms(500);
  sei();
  

  while (1) {
    set_led0(sw0_state());
    set_led1(sw1_state());
    set_led2(sw2_state());
    
    Usb2SerialTask();
    parse_command(); // read data from virtual comport
    
    touchpad_read(); // read data from touchpad
    
    if(sw0_state()){ // if left switch is active (enable x-axis)
      inc_target_plate_pos_x(-delta_x());
    }
    if(sw1_state()){ // if middle switch is active (enable y-axis)
      inc_target_plate_pos_y(-delta_y());
    }
    
    plate_task();
    if(plate_ready()){
      pos_report();
    }
  }


} // end of main