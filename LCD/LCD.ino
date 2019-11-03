
#include <Wire.h> // i2C 통신을 위한 라이브러리


#include <LiquidCrystal_I2C.h> // LCD 1602 I2C용 라이브러리


LiquidCrystal_I2C lcd(0x27,16,2); // 접근주소: 0x3F or 0x27

String line1 = "Hello, world!";
String line2 = "Hello, world!";

void setup()


{
  lcd.init(); // LCD 초기화
  
  lcd.backlight(); // 백라이트 켜기

}


void loop()
{
  line1.concat(line1.charAt(0));
  line1.remove(0, 1);

  line2.concat(line2.charAt(0));
  line2.remove(0, 1);
    
  lcd.setCursor(0,0); // 1번째, 1라인
  lcd.print(line1);
  
  lcd.setCursor(0,1); // 1번째, 2라인
  lcd.print(line2);

  delay(100);
}
