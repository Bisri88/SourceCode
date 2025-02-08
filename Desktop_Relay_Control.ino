//Using ESP32 Board Model
//Output Relay Using Normally Closed

#define pinRelay 23
char data;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pinRelay, OUTPUT);
digitalWrite(pinRelay, HIGH);
}

void sistemSerial()
{
  while(Serial.available()>0)
  {
    data = Serial.read();
    if(data == 'X')
    {
      digitalWrite(pinRelay, LOW);
    }
    else if(data == 'Y')
    {
      digitalWrite(pinRelay, HIGH);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
sistemSerial();
}
