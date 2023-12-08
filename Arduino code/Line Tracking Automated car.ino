#define in1 PB3
#define in2 PB5
#define in3 PB4
#define in4 PB10
#define enA PA10
#define enB PA8
#define echo PA2    //Echo pin
#define trigger PB0 //Trigger pin
#define servo PC0
int Set=15;
int distance_L, distance_F, distance_R; 



 int M1_Speed = 60; // speed of motor 1
 int M2_Speed = 60; // speed of motor 2
 int LeftRotationSpeed = 200;  // Left Rotation Speed
 int RightRotationSpeed = 200; // Right Rotation Speed


 void setup() {pinMode(echo, INPUT );// declare ultrasonic sensor Echo pin as input
pinMode(trigger, OUTPUT); // declare ultrasonic sensor Trigger pin as Output 
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

    pinMode(enA,OUTPUT);
    pinMode(enB,OUTPUT);

      pinMode(PA0, INPUT); // initialize Left sensor as an input
      pinMode(PA1, INPUT); // initialize Right sensor as an input

}

void loop() {

  int LEFT_SENSOR = digitalRead(PA0);
  int RIGHT_SENSOR = digitalRead(PA1);

if(RIGHT_SENSOR==0 && LEFT_SENSOR==0) {
    forward(); //FORWARD
}

  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
    right(); //Move Right
 }

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
    left(); //Move Left
}

  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
    Stop();  //STOP
 }
}



void forward()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

                analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}

void backward()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

                analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}

void right()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void left()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void Stop()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
}