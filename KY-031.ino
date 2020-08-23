// OPEN SOURCE
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //ENDEREÇO DO I2C E DEMAIS INFORMAÇÕES
int pin = 9;

void setup()
{
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  lcd.print("SENSOR DE CHOQUE");
  pinMode(pin,INPUT);
  delay(1000);
  lcd.clear();
}
void loop()
{
  int vibration = digitalRead(pin);
  lcd.setCursor(0,0);
  lcd.print("digital=" + (String)vibration + "  ");
  if(vibration == LOW)
  {
    lcd.setCursor(0,1);
    lcd.print("knock=detected");
  }
  else{
    lcd.setCursor(0,1);
    lcd.print("knock=NONE    ");
  }
  delay(500);
}
