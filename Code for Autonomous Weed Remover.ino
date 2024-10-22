int trigPin1=8;
int trigPin3=13;
int trigPin2=12;
int echoPin1=9;
int echoPin2=11;
int echoPin3=10;
int moterlf1=5;
int moterlf2=6;
int moterrt1=3;
int moterrt2=4;
int laser=2;
void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin1,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(trigPin3,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(echoPin2,INPUT);
  pinMode(echoPin3,INPUT);
  pinMode(moterlf1,OUTPUT);
  pinMode(moterlf2,OUTPUT);
  pinMode(moterrt1,OUTPUT);
  pinMode(moterrt2,OUTPUT);
  pinMode(laser,OUTPUT);
  pinMode(A0,INPUT);
}

void loop()
{
  long duration1,duration2,duration3;
  long distance1,distance2,distance3;
 digitalWrite(trigPin1,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin1,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin1,LOW);
 duration1=pulseIn(echoPin1,HIGH,10000);
 digitalWrite(trigPin2,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin2,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin2,LOW);
 duration2=pulseIn(echoPin2,HIGH,10000);
 digitalWrite(trigPin3,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin3,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin3,LOW);
 duration3=pulseIn(echoPin3,HIGH,10000);
 distance1=(duration1/2)*0.03435;
 distance2=(duration2/2)*0.03435;
 distance3=(duration3/2)*0.03435;
 Serial.print(distance1);
 Serial.print("\t");
 Serial.print(distance2);
 Serial.print("\t");
 Serial.print(distance3);
 Serial.print("\t");
 if(distance1==0)
 distance1=200;
 
  if(distance2==0)
 distance2=200;

  if(distance3==0)
 distance3=200;
 
 if(distance2>=35)
 {
    if((distance1>=27&&distance3>=27)||(distance1<=26&&distance3<=26))
      forward();
    if(distance1>=27&&distance3<=26)
      left();
 
    if(distance1<=26&&distance3>=27)
      right();
 }
 
 if(distance2<=34)
 {
    if(distance1>=27&&distance3<=26)
      left();
    if(distance1<=26&&distance3>=27)
      right();
    if(distance1<=26&&distance3<=26)
      back();
    if(distance1>=27&&distance3>=27)
    {
        if(distance1>=distance3)
          left();
        else
          right();
    }
 }

  Serial.print(analogRead(A0));
  Serial.print("\n");
   if(analogRead(A0)<=200)
   digitalWrite(laser,HIGH);
   else
   {
   digitalWrite(laser,LOW);
   delay(1000);
  }

}


void forward()
{
 digitalWrite(moterlf1,HIGH);
 digitalWrite(moterlf2,LOW);
 digitalWrite(moterrt1,HIGH);
 digitalWrite(moterrt2,LOW);
}
void right()
{
 digitalWrite(moterlf1,LOW);
 digitalWrite(moterlf2,HIGH);
 digitalWrite(moterrt1,HIGH);
 digitalWrite(moterrt2,LOW);
}
void left()
{
 digitalWrite(moterlf1,HIGH);
 digitalWrite(moterlf2,LOW);
 digitalWrite(moterrt1,LOW);
 digitalWrite(moterrt2,HIGH);
}
void back()
{
 digitalWrite(moterlf1,LOW);
 digitalWrite(moterlf2,HIGH);
 digitalWrite(moterrt1,LOW);
 digitalWrite(moterrt2,HIGH);
}
