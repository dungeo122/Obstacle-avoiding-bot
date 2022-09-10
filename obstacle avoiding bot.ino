// C++ code

int df;
int dl;
int dr;
char temp[5];
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 8, 7, 5, 2);

void setup()
{
  DDRD = B00011100; 
  pinMode(A0,INPUT);

  lcd.begin(16, 2);
  Serial.begin(9600);
}


void left(int a){
  analogWrite(10,a/12);
  analogWrite(11,0);
  analogWrite(6,a);
  analogWrite(9,0);
  lcd.print("left");
     lcd.setCursor(0,1);
     lcd.print("Speed ");
     lcd.print((a+63)*49.4);
     lcd.print("rpm" );
}

void right(int a){
  analogWrite(10,a);
  analogWrite(11,0);
  analogWrite(6,a/12);
  analogWrite(9,0);
    lcd.print("right");
     lcd.setCursor(0,1);
     lcd.print("Speed ");
     lcd.print((a+63)*49.4);
     lcd.print("rpm" );
}

void back(int a){
  analogWrite(10,0);
  analogWrite(11,a);
  analogWrite(6,0);
  analogWrite(9,a);
  lcd.print("backward");
     lcd.setCursor(0,1);
     lcd.print("Speed ");
     lcd.print((a+63)*49.4);
     lcd.print("rpm" );
}

void forward(int a){
  analogWrite(10,a);
  analogWrite(11,0);
  analogWrite(6,a);
  analogWrite(9,0);
  lcd.print("forward");
     lcd.setCursor(0,1);
     lcd.print("Speed ");
     lcd.print((a+63)*49.4);
     lcd.print("rpm" );
}

void loop()
{
  lcd.setCursor(0, 0);  
  Serial.readBytes(temp,5);
  String p = temp;
  if(p=="noWay"){
    lcd.println("No way");
  }
  else if(p=="frwd"){
    forward(analogRead(A0));
  }
  else if(p=="left"){
    left(analogRead(A0));
  }	
}