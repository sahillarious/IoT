#include <LiquidCrystal.h>
#define ECHO 9
#define TRIGGER 10
#define TIEMPO_MUESTREO 1000
#define PULSO_TRIGGER 1
int duration;
float distance;
float LED;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int num=1;


void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  digitalWrite(TRIGGER, HIGH);
  delay(PULSO_TRIGGER); 
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO,HIGH);
  distance = 0.01716 * duration;
  if(distance < 100)
  {
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("Maintain Social");
    lcd.setCursor(0,1);
    lcd.print("Distance");
    delay(50);
    //lcd.setCursor(0,1);
    //lcd.print("Distance");
  }
  else 
  {
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print(" ");
    delay(50);
    //lcd.setCursor(1,0);
    //lcd.print("Distance");
  }
    
}
 
