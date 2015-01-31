#include <avr/io.h> 
#include <stdlib.h>
#include "pins.h"





void init_leds(void) {
  DDRLED0 |= 1<<LED0;
  DDRLED1 |= 1<<LED1;
  DDRLED2 |= 1<<LED2;
}


void set_led0(uint8_t value){
  PORTLED0 &= ~(1<<LED0);
  PORTLED0 |= (!(value) & 0x01)<<LED0;
}

void set_led1(uint8_t value){
  PORTLED1 &= ~(1<<LED1);
  PORTLED1 |= (!(value) & 0x01)<<LED1;
}

void set_led2(uint8_t value){
  PORTLED2 &= ~(1<<LED2);
  PORTLED2 |= (!(value) & 0x01)<<LED2;
}


void init_sw(void) {
 DDRSW0 &= ~(1<<SW0);
 DDRSW1 &= ~(1<<SW1);
 DDRSW2 &= ~(1<<SW2);
 PORTSW0 |= (1<<SW0);
 PORTSW1 |= (1<<SW1);
 PORTSW2 |= (1<<SW2);
}


uint8_t sw0_state(void){
  return (PINSW0 & (1<<SW0))>>SW0;
}

uint8_t sw1_state(void){
  return (PINSW1 & (1<<SW1))>>SW1;
}

uint8_t sw2_state(void){
  return (PINSW2 & (1<<SW2))>>SW2;
}


