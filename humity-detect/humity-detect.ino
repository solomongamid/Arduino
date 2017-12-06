#include <LedControl.h>
LedControl leds= LedControl(12,11,10,1);
void setup() {
  // put your setup code here, to run once:
  leds.shutdown(0,false);
  leds.clearDisplay(0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int humity = analogRead(0);
  Serial.println(humity);
  if(humity < 650){
    leds.clearDisplay(0);
  leds.setLed(0,3,1,true);
  leds.setLed(0,4,1,true);
  leds.setLed(0,2,2,true);
  leds.setLed(0,5,2,true);
  leds.setLed(0,1,3,true);
  leds.setLed(0,6,3,true);
  leds.setLed(0,1,5,true);
  leds.setLed(0,2,5,true);
  leds.setLed(0,5,5,true);
  leds.setLed(0,6,5,true);
  leds.setLed(0,1,6,true);
  leds.setLed(0,2,6,true);
  leds.setLed(0,5,6,true);
  leds.setLed(0,6,6,true);
  } else {
 leds.clearDisplay(0);
   
  leds.setLed(0,2,1,true);
  leds.setLed(0,3,2,true);
  leds.setLed(0,4,2,true);
  leds.setLed(0,5,2,true);
  leds.setLed(0,6,1,true);
  leds.setLed(0,1,5,true);
  leds.setLed(0,2,5,true);
  leds.setLed(0,5,5,true);
  leds.setLed(0,6,5,true);
  leds.setLed(0,1,6,true);
  leds.setLed(0,2,6,true);
  leds.setLed(0,5,6,true);
  leds.setLed(0,6,6,true); 
  
  }

   
}
