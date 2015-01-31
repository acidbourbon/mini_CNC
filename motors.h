
#define X 0
#define Y 1


#define X0 2
#define X0_DDR DDRB
#define X0_PORT PORTB
#define X0_PIN PINB

#define X1 3
#define X1_DDR DDRB
#define X1_PORT PORTB
#define X1_PIN PINB

#define X2 4
#define X2_DDR DDRB
#define X2_PORT PORTB
#define X2_PIN PINB

#define X3 5
#define X3_DDR DDRB
#define X3_PORT PORTB
#define X3_PIN PINB


#define Y0 7
#define Y0_DDR DDRB
#define Y0_PORT PORTB
#define Y0_PIN PINB

#define Y1 6
#define Y1_DDR DDRB
#define Y1_PORT PORTB
#define Y1_PIN PINB

#define Y2 7
#define Y2_DDR DDRC
#define Y2_PORT PORTC
#define Y2_PIN PINC

#define Y3 6
#define Y3_DDR DDRC
#define Y3_PORT PORTC
#define Y3_PIN PINC


void set_x(uint8_t byte);
void set_y(uint8_t byte);
void init_motors(void);
uint8_t motor_step(uint8_t motor, int8_t direction);







