
#define SW0 4
#define DDRSW0 DDRD
#define PORTSW0 PORTD
#define PINSW0 PIND

#define SW1 5
#define DDRSW1 DDRC
#define PORTSW1 PORTC
#define PINSW1 PINC

#define SW2 4
#define DDRSW2 DDRC
#define PORTSW2 PORTC
#define PINSW2 PINC




#define LED0 1
#define DDRLED0 DDRB
#define PORTLED0 PORTB
#define PINLED0 PINB

#define LED1 0
#define DDRLED1 DDRB
#define PORTLED1 PORTB
#define PINLED1 PINB

#define LED2 6
#define DDRLED2 DDRD
#define PORTLED2 PORTD
#define PINLED2 PIND


void init_leds(void);
void set_led0(uint8_t value);
void set_led1(uint8_t value);
void set_led2(uint8_t value);
void init_sw(void);
uint8_t sw0_state(void);
uint8_t sw1_state(void);
uint8_t sw2_state(void);
  
  
  
  
  