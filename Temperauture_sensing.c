#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#define sensor A0
byte degree[8] = {0b00011,0b00011,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};


void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);
lcd.createChar(1, degree);
lcd.setCursor(0,0);
lcd.print("   JITESH   ");
lcd.setCursor(0,1);
lcd.print("   ROOM   ");
delay(2000);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
float reading = analogRead(sensor);
float temperature = reading*(5.0/1023.0)*100;
delay(10);

lcd.clear();
lcd.setCursor(2,0);
lcd.print("TEMPERATURE");
Serial.println(temperature);
lcd.setCursor(4,1);
lcd.print(temperature);
lcd.write(1);
delay(1000);
}