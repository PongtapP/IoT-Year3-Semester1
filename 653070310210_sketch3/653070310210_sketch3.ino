#define sw1 D5
#define ledPin1 D6
int st_sw1 = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1,OUTPUT);
  pinMode(sw1,INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  st_sw1 = digitalRead(sw1);
  digitalWrite(ledPin1,not(st_sw1));
}
