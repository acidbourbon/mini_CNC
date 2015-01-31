#include <avr/io.h> 
#include <stdlib.h>
#include <util/delay.h>
#include "motors.h"
#include "pins.h"





/* motor stuff */

uint8_t phase_pattern[4] = { 0b00001010, 0b00001001, 0b00000101, 0b00000110};
    
    
void set_x(uint8_t byte) {
  X0_PORT &= ~(1<<X0);
  X1_PORT &= ~(1<<X1);
  X2_PORT &= ~(1<<X2);
  X3_PORT &= ~(1<<X3);

  X0_PORT |= ((byte & (1<<0))>>0)<<X0;
  X1_PORT |= ((byte & (1<<1))>>1)<<X1;
  X2_PORT |= ((byte & (1<<2))>>2)<<X2;
  X3_PORT |= ((byte & (1<<3))>>3)<<X3;
}

void set_y(uint8_t byte) {
  Y0_PORT &= ~(1<<Y0);
  Y1_PORT &= ~(1<<Y1);
  Y2_PORT &= ~(1<<Y2);
  Y3_PORT &= ~(1<<Y3);

  Y0_PORT |= ((byte & (1<<0))>>0)<<Y0;
  Y1_PORT |= ((byte & (1<<1))>>1)<<Y1;
  Y2_PORT |= ((byte & (1<<2))>>2)<<Y2;
  Y3_PORT |= ((byte & (1<<3))>>3)<<Y3;
}

void init_motors(void){
  set_x(0);
  set_y(0);
  X0_DDR |= (1<<X0);
  X1_DDR |= (1<<X1);
  X2_DDR |= (1<<X2);
  X3_DDR |= (1<<X3);
  Y0_DDR |= (1<<Y0);
  Y1_DDR |= (1<<Y1);
  Y2_DDR |= (1<<Y2);
  Y3_DDR |= (1<<Y3);
  
  
//   XEND1_as_pullup();
//   XEND2_as_pullup();
//   YEND1_as_pullup();
//   YEND2_as_pullup();
  
}



uint8_t motor_step(uint8_t motor, int8_t direction) { // motor: M1 or M2, direction +1 or -1, 0 for coil deactivation

  uint8_t next_pattern, next_phase;
  static uint8_t phase_memory[2] = { 0, 0 };
  void (*setport)(uint8_t);
  setport = &set_x;
  
  switch(motor) {
    case X:
      setport = &set_x;
      break;
    case Y:
      setport = &set_y;
      break;
  }

  next_phase = (phase_memory[motor] + 4 + direction) % 4;
  phase_memory[motor] = next_phase;
  

  next_pattern = phase_pattern[next_phase];
  if (direction != 0) {
      (*setport)(next_pattern);
  } else {
      (*setport)(0);
  }

  return next_pattern;

}




  


