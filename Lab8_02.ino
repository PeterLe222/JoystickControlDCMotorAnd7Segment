void setup() {
  pinMode(A0,INPUT);  // x axis
  pinMode(A1,INPUT);  // y axis
  Serial.begin(9600);
  pinMode(3,OUTPUT);  // motor
  /* pin 4 to 10 connects to 7-segment */
  pinMode(4,OUTPUT);  // A
  pinMode(5,OUTPUT);  // B
  pinMode(6,OUTPUT);  // C
  pinMode(7,OUTPUT);  // D
  pinMode(8,OUTPUT);  // E
  pinMode(9,OUTPUT);  // F
  pinMode(10,OUTPUT); // G
}

const byte LEDs[] = {10,9,8,7,6,5,4};
int x,y,motorSpeed;
byte num_0 = 0b0000001;
byte num_9 = 0b0000100;

void loop() {
  
  x = analogRead(A0);
  y = analogRead(A1);
  Serial.print("x = ");Serial.println(x);
  Serial.print("y = ");Serial.println(y);
  if (500 < y < 506 && 519 < x < 525)
  {
    analogWrite(3,0);
    Serial.println("speed = 0");
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(LEDs[i],bitRead(num_0,i));  
    }
  }
  if (500 < y < 506 && x > 525)
  {
    motorSpeed = map(x,0,1025,0,255);
    analogWrite(3,x);
    Serial.print("speed = ");Serial.println(motorSpeed);
    if (motorSpeed > 250)
    {
      for (int i = 0; i < 7; i++)
      {
        digitalWrite(LEDs[i],bitRead(num_9,i));  
      }
      delay(100);
    }
  }
}
