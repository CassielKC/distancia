#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
   pinMode(A0,INPUT);
   lcd.begin(16, 2);
   Serial.begin(9600);
 
}

void loop() 
{
    float v,x1,x2,a=0.0146, b=0.5322, c=3.8889;
    delay(1000);
    v=analogRead(A0);
    v=v*(5.0/1023.0);
    lcd.setCursor(0,0);
    lcd.print("Volts:");
    lcd.setCursor(9,0);
    lcd.print(v);
    lcd.setCursor(15,0);
    lcd.print("V");
    c=c-v;
    x1 = (b + sqrt( (b*b) - (4 * a * c) ) ) / (2.0 * a);
    x2 = (b - sqrt( (b*b) - (4 * a * c) ) ) / (2.0 * a);
    Serial.print(" X1 ");
    Serial.println(x1);
    Serial.print(" x2 ");
    Serial.println(x2);
    lcd.setCursor(0,1);
    lcd.print("Distancia:");
    lcd.setCursor(10,1);
    lcd.print(x2);
    lcd.setCursor(14,1);
    lcd.print("mm");
 }
