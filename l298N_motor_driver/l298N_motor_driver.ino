int IN1 = 2;
int IN2 = 3;

int IN3 = 4;
int IN4 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
//  pinMode(9, OUTPUT); 
//  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:   

  //Controlling speed (0 = off and 255 = max speed):
//  analogWrite(9, 100); //ENA pin
//  analogWrite(10, 200); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(IN1, HIGH); // Forward (Left)
  digitalWrite(IN2, LOW); // Forward (Left)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1000);
  digitalWrite(IN1, LOW); // Forward (Left)
  digitalWrite(IN2, LOW); // Forward (Left)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);

  
}
