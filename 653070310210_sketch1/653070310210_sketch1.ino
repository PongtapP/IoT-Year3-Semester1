#define ledPin1 D0
#define ledPin2 D4
#define ledPin3 D5
void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
}

void loop() {
  digitalWrite(ledPin1, 0);
  digitalWrite(ledPin2, 0);
  digitalWrite(ledPin3, 1);
  delay(1000);
  digitalWrite(ledPin1, 0);
  digitalWrite(ledPin2, 1);
  digitalWrite(ledPin3, 1);
  delay(1000);
  digitalWrite(ledPin1, 1);
  digitalWrite(ledPin2, 1);
  digitalWrite(ledPin3, 1);
  delay(1000);
  digitalWrite(ledPin1, 0);
  digitalWrite(ledPin2, 0);
  digitalWrite(ledPin3, 0);
  delay(1000);
}
