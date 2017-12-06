void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
 int fireDetect = analogRead(0); 
 Serial.println(fireDetect);
 if(fireDetect < 200){
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
 } else {
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
 }
 
}
