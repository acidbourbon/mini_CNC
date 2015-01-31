#define PHASE_DELAY_US 10000

// #define TIMER_STEP 6.4e-5

// #define TIMER_SETTING PHASE_DELAY_US*1e-6/TIMER_STEP




uint8_t move_plate(void);
uint8_t plate_ready(void);

// ISR( TIMER1_COMPA_vect );
// void init_plate_timer(void);
int32_t get_plate_pos_x(void);
int32_t get_plate_pos_y(void);
void set_plate_pos_x(int32_t value);
void set_plate_pos_y(int32_t value);
int32_t get_target_plate_pos_x(void);
int32_t get_target_plate_pos_y(void);
void set_target_plate_pos_x(int32_t value);
void set_target_plate_pos_y(int32_t value);
void inc_target_plate_pos_x(int32_t value);
void inc_target_plate_pos_y(int32_t value);
void plate_task(void);