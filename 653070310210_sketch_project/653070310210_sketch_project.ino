#define BLYNK_TEMPLATE_ID "TMPL6142GzpHJ"
#define BLYNK_TEMPLATE_NAME "PONGTAP PATTAWOHARN Project IoT"
#define BLYNK_AUTH_TOKEN "kyT412AOmOY6s_BWTA3MFINctaLpFUXs"

#include <BlynkSimpleEsp8266.h>
#include <MQ2.h>

char auth[] = BLYNK_AUTH_TOKEN;   // token from Blynk
char ssid[] = "MusketBears";      // Wi-Fi name for blynk.begin
char pass[] = "asd66180";         // Wi-Fi password for blynk.begin

int outputPin = D0;               // led and buzzer pin
int pin = A0;                     // mq-2 pin
float lpg, co, smoke;             //  variable for input value from mq-2
MQ2 mq2(pin);                     // libary mq-2=pin=a0

void setup()
{
  Serial.begin(9600);             //serial for print
  delay(100);
  pinMode(outputPin, OUTPUT);     //output to led and buzzer
  digitalWrite(outputPin, LOW);   // tuen off led and buzzer

  Blynk.begin(auth, ssid, pass);  //connect blynk and wifi

  mq2.begin();                    //calibrate function from libary #include <MQ2.h> for calibrate sensor // example R=146.7Kohm
}

void loop() {
  float* values = mq2.read(true); //set it false if you don't want to print the values to the Serial and set it true if you want to print the values to the Serial
  co = mq2.readCO();              // set carbonmonoxide value to valible
  smoke = mq2.readSmoke();        // set smoke value to valible
  lpg = mq2.readLPG();            // set lpg value to valible

  Serial.print("LPG:");           
  Serial.print(lpg);              
  Serial.print( "ppm" );
  Serial.print("    ");   
  Serial.print("CO:"); 
  Serial.print(co);               // example print  "LPG:0.23ppm    CO:17.23ppm    SMOKE:10.11ppm"
  Serial.print( "ppm" );          // example print  "LPG:0.27ppm    CO:24.12ppm    SMOKE:15.22ppm"
  Serial.print("    ");   
  Serial.print("SMOKE:"); 
  Serial.print(smoke);
  Serial.print( "ppm" );
  Serial.print("\n");

  Blynk.virtualWrite(V1, smoke);  //send value smoke to V1 datastream blynk
  Blynk.virtualWrite(V2, lpg);    //send value lpg to V2 datastream blynk
  Blynk.virtualWrite(V3, co);     //send value co to V3 datastream blynk

  if (smoke > 40 ) {
    Blynk.logEvent("smoke", "Smoke Detected!");         //call event smoke from blynk
    digitalWrite(outputPin, HIGH);// turn on led and buzzer
  }
  else {
    digitalWrite(outputPin, LOW); // turn off led and buzzer
  }
  
  if (lpg > 40 ) {
    Blynk.logEvent("lpg", "LPG Detected!");             //call event lpg from blynk
    digitalWrite(outputPin, HIGH);// turn on led and buzzer
  }
  else {
    digitalWrite(outputPin, LOW); // turn off led and buzzer
  }

  if (co > 40 ) {
    Blynk.logEvent("co", "Carbon Monoxide Detected!");  //call event co from blynk
    digitalWrite(outputPin, HIGH);// tuen on led and buzzer
  }
  else {
    digitalWrite(outputPin, LOW); // turn off led and buzzer
  }
  delay(1000);
}