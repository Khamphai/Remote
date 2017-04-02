#include "IRremote.h"

int LED = 13;
int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
      if(results.value == 0xFF6897){
        digitalWrite(LED, HIGH);
      }else if(results.value == 0xFF9867){
        digitalWrite(LED, LOW);
      }
    irrecv.resume(); // Receive the next value
  }
}
