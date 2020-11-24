#include <LiquidCrystal.h>

//#include <LiquidCrystal_I2C.h> //引用I2C库 
//LiquidCrystal_I2C lcd(0x27, 16, 2);//I2C设备地址、列数，行数
LiquidCrystal lcd(0x27, 16, 2);
unsigned long starttime;//计时开始时刻
unsigned long stoptime;//计时终止时刻
unsigned long looptime;//计时长度
unsigned char k=0;//光标初始位置
unsigned char Nowhour=12;//小时调整
unsigned char Nowminute=13;//分钟调整
void setup() {
  // put your setup code here, to run once:
  lcd.init(); // 初始化LCD
  lcd.backlight(); //设置LCD背景灯亮
  starttime = millis();//上电计时开始（毫秒）
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char Second, Hsecond, Lsecond, Minute, Hminute, Lminute, Hour, Hhour, Lhour;
  
  stoptime = millis();
  looptime = stoptime - starttime;
  Second = (looptime / 1000) % 60;//计算秒

  Hsecond = Second / 10;//秒的十位
  Lsecond = Second % 10;//秒的个位

  Minute = (Nowminute+(looptime / 1000) / 60) % 60;
  Hminute = Minute / 10;//分钟的十位
  Lminute =Minute % 10;//分钟的个位

  Hour = (Nowhour+(looptime / 1000) / 3600) % 24;
  Hhour = Hour / 10;//小时的十位
  Lhour = Hour% 10;//小时的个位
  

  Lcd_XianShi(k%16, 0, Hhour);//显示小时的十位
  Lcd_XianShi((k+1)%16, 0, Lhour);//显示小时的个位

  Lcd_XianShi((k+3)%16, 0, Hminute);//显示分钟的十位
  Lcd_XianShi((k+4)%16, 0, Lminute);//显示分钟的个位

  Lcd_XianShi((k+6)%16, 0, Hsecond);//显示秒的十位
  Lcd_XianShi((k+7)%16, 0, Lsecond);//显示秒的个位

  if (Second % 2 == 1)//显示冒号
  {
    lcd.setCursor((k+2)%16, 0);
    lcd.print(":");
    lcd.setCursor((k+5)%16, 0);
    lcd.print(":");
  }
  if (Second % 2 == 0)//不显示冒号
  {
    lcd.setCursor((k+2)%16, 0);
    lcd.print(" ");
    lcd.setCursor((k+5)%16, 0);
    lcd.print(" ");
  }

}

void Lcd_XianShi(unsigned char a, unsigned char b, unsigned char c)
{
  lcd.setCursor(a, b); //设置显示光标位置
  lcd.print(c);
 
}
