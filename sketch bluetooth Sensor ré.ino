

#include <SoftwareSerial.h>


SoftwareSerial bluetooth(10, 11); // RX, TX

// Pin declarations
const int TRIG = 3;
const int ECHO = 2;
const int pir = 6;
const int ledGreen = 7;
const int ledRed = 8; // 
const int buzzer = 9;


float seno;
int frequencia;

void setup() {
  Serial.begin(9600); 
  bluetooth.begin(9600); 

  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // PIR sensor configuration
  pinMode(pir, INPUT);

  // LED configurations
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT); 

  // Buzzer configuration
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int distancia = sensor_morcego(TRIG, ECHO);
  int pirState = digitalRead(pir); 

  // Check for Bluetooth input
  if (bluetooth.available()) {
    char comando = bluetooth.read(); 
    if (comando == 'L') {
      digitalWrite(ledGreen, HIGH); 
    } else if (comando == 'D') {
      digitalWrite(ledGreen, LOW); 
    }
  }

 
}


int sensor_morcego(int trigPin, int echoPin) {
  // Example implementation
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; 
  return distance;
}
