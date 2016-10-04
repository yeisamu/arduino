// include the library code:
#include <LiquidCrystal.h>
#include <SoftwareSerial.h> 
const int sensorPin= A0;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
SoftwareSerial BT(0,1); //10 RX, 11 TX.

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  BT.begin(9600); //Velocidad del puerto del módulo Bluetooth
  Serial.begin(9600);
  // Print a message to the LCD.
  lcd.print("lagrimon");
}

void loop() {
  char letra=BT.read();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
 // lcd.print(millis() / 1000);
 int value = analogRead(sensorPin);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  lcd.print(celsius);
   lcd.setCursor(10, 1);
  lcd.print(letra);
  Serial.println(" C");
  delay(1000);
   if(BT.available())
  {
    Serial.write(BT.read());
  }
 
  if(Serial.available())
  {
     BT.write(Serial.read());
  }
}

