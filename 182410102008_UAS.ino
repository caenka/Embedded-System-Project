#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11);
  
int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 400; 
int enable=13;
int rightdc=12;
int leftdc=7;

void setup()
{
pinMode(redled, OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT);
  //DC motor
pinMode(enable, OUTPUT);
pinMode(rightdc, OUTPUT);
pinMode(leftdc, OUTPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop(){
  int analogValue = analogRead(sensor);
  Serial.print(analogValue);
  if(analogValue>sensorThresh){
    start();
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
    tone(buzzer,1000,10000);
    lcd.setCursor(0,0);
    lcd.print("KEBAKARAN!");
    lcd.setCursor(0,1);
    lcd.print("PANGGIL DAMKAR!");
    delay(1000);
    lcd.clear();
  }else{
    stop();
    digitalWrite(greenled,HIGH);
    digitalWrite(redled,LOW);
    noTone(buzzer);
    lcd.setCursor(0,0);
    lcd.print("PERIKSA RUMAH");
    lcd.setCursor(0,1);
    lcd.print("SEBELUM KELUAR");
    delay(1000);
    lcd.clear();
  }      
}
              
void start(){
  digitalWrite(enable, HIGH);
  digitalWrite(rightdc, HIGH);
  digitalWrite(leftdc, LOW);
  
}

void stop(){
  digitalWrite(enable, HIGH);
  digitalWrite(rightdc, HIGH);
  digitalWrite(leftdc, HIGH);
  
}              