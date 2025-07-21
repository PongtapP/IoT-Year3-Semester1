#include <Adafruit_NeoPixel.h>
#define NUMSLEDs 2
#define PINSLEDs 10
Adafruit_NeoPixel SLEDs = Adafruit_NeoPixel(NUMSLEDs, PINSLEDs, NEO_RGB + NEO_KHZ800);

#define sw1 D4
#define sw2 D5
#define ledPin1 D6
#define ledPin2 D7

int st_sw1 = 0;
int st_sw2 = 0;
int st_1 = 0;
int st_2 = 0;
int last_st_sw1 = 1;
int last_st_sw2 = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);               
    SLEDs.begin();                    
    SLEDs.show();                      
    pinMode(ledPin1, OUTPUT);      
    pinMode(ledPin2, OUTPUT);
    pinMode(sw1, INPUT);               
    pinMode(sw2, INPUT);             
}

void loop() {
  // put your main code here, to run repeatedly:
   st_sw1 = digitalRead(sw1);        
    if ((st_sw1 == 0) && (last_st_sw1 == 1)) {   
        st_1 = !st_1;                              
        digitalWrite(ledPin1, st_1);                 
        delay(250);
    }
    last_st_sw1 = st_sw1;          

    st_sw2 = digitalRead(sw2);       
    if ((st_sw2 == 0) && (last_st_sw2 == 1)) {   
        st_2 = !st_2;                           
        digitalWrite(ledPin2, st_2);             
        delay(250);
    }
    last_st_sw2 = st_sw2;   
}
