#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>   
#include <Wire.h>    
  
int trigPin = 13;
int echoPin = 12;
long sure ;
long uzaklik;
int ServoPin = 10;
const byte satir = 4;
const byte sutun = 3;
LiquidCrystal_I2C lcd (0x27, 16, 2);     //LCD  ekranın pinleri   

Servo motor;

char tus_takimi [satir] [sutun] = {
 {'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'},

};

byte satir_pinleri[satir] = {2, 3, 4, 5};
byte sutun_pinleri[sutun] = {6, 7, 8};

Keypad kasa = Keypad(makeKeymap(tus_takimi), satir_pinleri, sutun_pinleri, satir, sutun);

String girilen_sifre="";
String sifre="5555#";

void setup()
{
  if (uzaklik=15);

 pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  lcd.init();          
lcd.backlight();
//pinMode(buzzer, OUTPUT);     //Buzzerin yukarıdaki degiskende belirtiği 11 pin yeri
lcd.print(" Elektronik ");             //2 bölümden oluşan ledin üst kısmında yazan yazı
lcd.setCursor(0,1);                      //LCD nin alt kısmına geçiş 
lcd.print(" Sifreli Kilit ");           //2 bölümden oluşan ledin alt kısmında yazan yazı 
delay(2000);                               //2   bekleme süresi
lcd.clear();                                  //LCD ekranın temizlenmesi
lcd.print("Sifreyi Girin: ");
     motor.attach(ServoPin);

}
void loop()
{
    digitalWrite(trigPin,LOW);
  delay(1000);
    digitalWrite(trigPin,HIGH);
  delay(1000);
    digitalWrite(trigPin,LOW);
    sure=pulseIn(echoPin,HIGH);
    uzaklik=sure/2/29.154;

    Serial.print("Yakinlasan cisim:");
    Serial.print(sure);
    Serial.println("hareket ediyor.");

        Serial.print("Mesafe:");
    Serial.print(uzaklik);
    Serial.println("CM");
    if(uzaklik>10){
      delay(5000);
      lcd(low)
    }
    delay(500);



  char tus = kasa.getKey();
   
  if (tus != NO_KEY)
  {
    
    girilen_sifre = girilen_sifre+tus;
    Serial.println(girilen_sifre);
   digitalWrite(ses,1);
   delay(100);
   digitalWrite(ses,0);
   delay(100);
    
  }

  if(tus == '#')
    {
      
      if(girilen_sifre == sifre)
      
      {
        lcd.print("Sifre onaylandi!");      // Ekrana yazını yazılması
 delay(3000); 
 lcd.setCursor(0,1);                       // lcd ekranın alt kızmı
 lcd.clear();
 lcd.print("Sifreyi Girin:");
 lcd.setCursor(0,1);
        Serial.println("DOGRU SiFRE");
        delay(3000);
         girilen_sifre="";
        tone(11,1000,1000);
         motor.write(180);
         delay(5000);
         motor.write(90);
         delay(1000);
         lcd.clear();                                   
        }
      else
      {
      Serial.print("YANLIS :");
      Serial.println(girilen_sifre);
      digitalWrite(ses,1);
      tone(11,1000,500);
      delay(1000);
      tone(11,1000,500);
        delay(1000);
        digitalWrite(ses,0);
        lcd.clear(); 
 lcd.print("Tekrar deneyin...");
 lcd.setCursor(0,1); 
 delay(1000);
 lcd.clear();
 lcd.print("Sifreyi girin:");
 lcd.setCursor(0,1);    
       girilen_sifre="";
      
      }
      
      }
  
  }