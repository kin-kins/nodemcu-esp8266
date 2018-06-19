void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2,INPUT);
digitalWrite(2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
int c=analogRead(A0);
int leakage=digitalRead(2);
if(leakage==0)
{
  Serial.println("Lekage");
}
//Serial.println(c);
delay(1000);
}
