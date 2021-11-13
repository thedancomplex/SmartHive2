#define BLIMP_ID 5

#if !defined(COMS_H)
  #include "coms.h"
#endif

#if !defined(INTR_H)
  #include "intr.h"
#endif





void setup() {
  Serial.begin(115200);
  coms_setup();
  intr_setup(1.0);
}


void do_intr()
{
  if(intr_step())
  {
    Serial.println("#############################"); 
//    int val = coms_status();
//    if(val){ coms_connect();}
//    if(val){ autonomy_mode_reset();}
  }
}




void loop() {
  //Serial.println("-------");
  long tick = millis();

//  get_coms();
  do_intr();

  long tock = millis();
  //Serial.println(tock-tick);
  delay(5);

}
