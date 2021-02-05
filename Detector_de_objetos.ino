#include<LiquidCrystal.h>

LiquidCrystal lcd(4,5,6,7,8,9);
int trigpin = 2;
int echopin = 3;
long duration;
void setup()
{
  lcd.begin(16,2);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);

}

void loop()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
  duration = pulseIn(echopin,HIGH);
  
  int distCm = duration*0.034/2;
  int distIn = duration*0.0133/2;
  
  lcd.setCursor(0,0);
  lcd.print ("Distance: ");
  lcd.print(distCm);
  lcd.print ("cm");
  delay(10);
  
  lcd.setCursor(0,1);
  lcd.print ("Distance: ");
  lcd.print(distIn);
  lcd.print ("in");
  delay(10);
}