#include <LiquidCrystal.h>

#include <DHT.h>

DHT dht(7,DHT11);
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  //lcd.print("SULIMAN KING ");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  float humity = dht.readHumidity();
  Serial.println(temp);
  lcd.setCursor(0,0);
  lcd.print("TEMP :");
  lcd.print(temp);
  lcd.write(223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("HUMITY :");
  lcd.print(humity);
  lcd.print("%");
  
 /* if(isnan(temp)){
    Serial.println("Failed to read from DHT sensor");
    return; 
  } */
  
}
