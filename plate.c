#include <avr/io.h> 
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "motors.h"
#include "plate.h"
#include "misc.h"
#include "pins.h"



// plate stuff

volatile int32_t plate_pos_x = 0,plate_pos_y = 0;
volatile int32_t target_plate_pos_x = 0,target_plate_pos_y = 0;

volatile uint8_t ready = 0;
volatile uint8_t busy = 0;

int32_t get_plate_pos_x(void){
  return plate_pos_x;
}
int32_t get_plate_pos_y(void){
  return plate_pos_y;
}
void set_plate_pos_x(int32_t value){
  plate_pos_x = value;
}
void set_plate_pos_y(int32_t value){
  plate_pos_y = value;
}
int32_t get_target_plate_pos_x(void){
  return target_plate_pos_x;
}
int32_t get_target_plate_pos_y(void){
  return target_plate_pos_y;
}
void set_target_plate_pos_x(int32_t value){
  target_plate_pos_x = value;
  busy = 1;
}
void set_target_plate_pos_y(int32_t value){
  target_plate_pos_y = value;
  busy = 1;
}
void inc_target_plate_pos_x(int32_t value){
  target_plate_pos_x += value;
//   busy = 1;
}
void inc_target_plate_pos_y(int32_t value){
  target_plate_pos_y += value;
//   busy = 1;
}

uint8_t plate_ready(void){
  if(ready){
    ready = 0;
    return 1;
  } else {
    return 0;
  }
}



uint8_t move_plate(void){
  int32_t todo_x,todo_y = 0;
  int8_t signum;
  todo_x = target_plate_pos_x-plate_pos_x;
  todo_y = target_plate_pos_y-plate_pos_y;
  
  

  
//   //if end switch closed, stop moving against the stop!
//   if(XEND1_state() && (sign(todo_x) == 1) ){
//     todo_x = 0;
//     target_plate_pos_x = plate_pos_x;
//   }
//   if(XEND2_state() && (sign(todo_x) == -1) ){
//     todo_x = 0;
//     target_plate_pos_x = plate_pos_x;
//   }
//   if(YEND1_state() && (sign(todo_y) == 1) ){
//     todo_y = 0;
//     target_plate_pos_y = plate_pos_y;
//   }
//   if(YEND2_state() && (sign(todo_y) == -1) ){
//     todo_y = 0;
//     target_plate_pos_y = plate_pos_y;
//   }
  
  if( (todo_x!=0) || (todo_y!=0) ){
    busy = 1;
  };
  
  
  signum = sign(todo_x);
  motor_step(X,signum);
  todo_x -= signum;
  plate_pos_x += signum;
  
  
  
  signum = sign(todo_y);
  motor_step(Y,signum);
  todo_y -= signum;
  plate_pos_y += signum;
  
  
  
  _delay_us(PHASE_DELAY_US);
  
  if( busy && (todo_x==0) && (todo_y==0) ){
    busy=0;
    return 1;
  } else {
    return 0;
  }
}


void plate_task(void) {
  if(move_plate()){
    ready = 1;
  }
}

// the following is only needed if used with interrupt

// void init_plate_timer(void){
//   TCCR1B |= (1<<CS10) | (1<<CS12) | (1<<WGM12);
//   TCCR1C |= (1<<FOC1A);
//   OCR1A = TIMER_SETTING;
//   TIMSK1 |= (1<<OCIE1A);
//   
// }

// ISR( TIMER1_COMPA_vect ) {
//   if(move_plate()){
//     ready = 1;
//   }
// }

  


