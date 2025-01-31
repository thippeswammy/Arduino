#include <LiquidCrystal.h> 
int Contrast=90;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int Wl=20;
int Temp=35;
int Hum=50;
bool motorRelay=true;
void setup()
{
  analogWrite(6,Contrast);
  lcd.begin(16, 2);

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Welcome  To  ");
  lcd.setCursor(0, 1);
  lcd.print("    AgVENTURE   ");
  delay(2000);
} 


void loop()
{ 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motor:");
  lcd.setCursor(6, 0);
  if(motorRelay){
    lcd.print("On  ");
  }else{
    lcd.print("OFF ");
  }


  lcd.setCursor(10, 0);
  lcd.print("Lev:");
  lcd.setCursor(14, 0);
  lcd.print(Wl);


  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.setCursor(5, 1);
  lcd.print(Temp);
  lcd.print("c");


  lcd.setCursor(10, 1);
  lcd.print("H:");
  lcd.setCursor(12, 1);
  lcd.print(Hum);
  lcd.print("%");

}
