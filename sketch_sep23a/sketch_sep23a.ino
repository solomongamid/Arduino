#include <DHT.h>


#include <ESP8266WiFi.h>

DHT dht(13,DHT11);
const char* ssid = "SimplonUnifi";
const char* password = "simplonco";


WiFiServer server(80);

void setup() {
  dht.begin();
  delay(10);
  // put your setup code here, to run once:
 pinMode(15,OUTPUT);
 Serial.begin(115200);
 delay(10);
 
 Serial.print("Connecting to ");
 Serial.println(ssid);
 
 WiFi.begin(ssid, password);

 while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");
 }
 Serial.println("WiFi Connected");
 digitalWrite(15,HIGH);
 Serial.print("Web Server IP: ");
 Serial.println(WiFi.localIP());
 server.begin();
 
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  float humity = dht.readHumidity();
  Serial.println(temp);
  Serial.println(humity);
  
 WiFiClient client = server.available();
 if(!client){
  return;
 }

 Serial.println("New request");
 while(!client.available()){
  delay(1);
 }

 String request = client.readStringUntil('\r');
 Serial.println(request); 

 int value = LOW ;
 if(request.indexOf("LED=ON") != -1){
  digitalWrite(15, HIGH);
  value = HIGH;
 } 
 if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(15, LOW);
    value = LOW;
  }

 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println("");
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.println("  <link href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" rel=\"stylesheet\">");
 client.println(" <body>");
 client.println("    <h1> SU Server </h1>");
 client.println("   <a href=\"LED=ON\"><button class='btn btn-success'> TURN ON </button></a>");
 client.println("   <a href=\"LED=OFF\"><button class='btn btn-info'> TURN OFF </button></a>");
 
 client.println("<h3> THE TEMP NOW :");
 client.println(temp);
 client.write("*");
 client.println("C");
 client.println( "</h3>");
 client.println("<h3> THE HUMIDITY NOW : ");
 client.println(humity);
 client.println("%");
 client.println("</h3>");
 client.println("</body>");
 client.println("</html>");
 delay(1);
  
 /*digitalWrite(13,HIGH);
 delay(1000);
 digitalWrite(13,LOW);
 delay(1000);*/
}
