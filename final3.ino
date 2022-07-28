#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);

float tempC;
int VEN = 9; 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
   

}

void loop() {
   tempC = analogRead(A0);


  tempC = (5.0 * tempC * 100.0)/1024.0;
  
  lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  lcd.setCursor(0,1);
  lcd.print(tempC);
  //Serial.print("Temperatura del sistema: ");
  //Serial.print(tempC);  
  //Serial.print("\n");
  //delay(50);
  
    if(tempC>20 && tempC<26 ){
        tempC=analogRead(A0);
        tempC = (5.0 * tempC * 100.0)/1024.0;
        //Serial.print("Temperatura rango 1: ");
        //Serial.print(tempC);
        //Serial.print("\n");
        //delay(200);
        lcd.setCursor(0,0);
        lcd.print("Temperatura 1:");
        lcd.setCursor(0,1);
        lcd.print(tempC);
        
        analogWrite(VEN, 175);
        delay(500);
        
        }
    //analogWrite(VEN, LOW);    
    
    
    if(tempC>=26 && tempC<30 ){
        tempC=analogRead(A0);
        tempC = (5.0 * tempC * 100.0)/1024.0;
        //Serial.print("Temperatura rango 2: ");
        //Serial.print(tempC);
        //Serial.print("\n");
        lcd.setCursor(0,0);
        lcd.print("Temperatura 2:");
        lcd.setCursor(0,1);
        lcd.print(tempC);
        
        analogWrite(VEN, 200);
        delay(500);    
    }

    //analogWrite(VEN, LOW);    
    

    
    if(tempC>=30 && tempC<80 ){
      tempC=analogRead(A0);
      tempC = (5.0 * tempC * 100.0)/1024.0;
      //Serial.print("Temperatura rango 3: ");
      //Serial.print(tempC);
      //Serial.print("\n");
      lcd.setCursor(0,0);
      lcd.print("Temperatura 3:");
      lcd.setCursor(0,1);
      lcd.print(tempC);
      
      analogWrite(VEN, 255);   
      delay(500);  
    }

    //analogWrite(VEN, LOW);    
    
}
