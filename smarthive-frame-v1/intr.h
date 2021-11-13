#define INTR_H
#define INTR_US_TO_SEC 1000000.0
#define INTR_LED_PIN 13
unsigned long intr_tick_ul = 0;
unsigned long intr_tock_ul = 0;

double T_des = 1.0;

void intr_setup(double val);
void intr_setup();

int intr_step()
{
  intr_tock_ul = micros();
  unsigned long dt = intr_tock_ul - intr_tick_ul;
  double dt_d = (double)dt / INTR_US_TO_SEC;
  if( dt_d >= T_des )
  {
    intr_tick_ul = intr_tock_ul;
    digitalWrite(INTR_LED_PIN, !digitalRead(INTR_LED_PIN));
    return 1;
  }
  return 0;
}


void intr_setup(double val)
{
  if (val > 0.0) T_des = val;
  intr_setup();
}


void intr_setup()
{
  pinMode(INTR_LED_PIN, OUTPUT);
  intr_tick_ul = micros();
}
