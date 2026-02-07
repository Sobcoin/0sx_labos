#include <math.h>
enum EtatAppli { BLINK,
                 FADE,
                 HIGHANDLOW };

EtatAppli etatActuelle = BLINK;

int numberOfBlink = ceil(6 / 2);
const int TIMEOFBLINK = 250;
const int LEDPIN = 13;
const int MAXFADE = 255;
const int MINFADE = 0;
const int TIMEFADE = 2048;
int stepOfFading = ceil(TIMEFADE / MAXFADE);
const int STUDENTNUMBER = 2379367;


void blinking() {
  Serial.println("Clignotement - " + STUDENTNUMBER);
  for (int i = 0; i < numberOfBlink; i++) {
    // Allumage de la LED sur la pin 13
    digitalWrite(LEDPIN, HIGH);
    // Attente de 500 millisecondes
    delay(250);
    // Extinction de la LED sur la pin 13
    digitalWrite(LEDPIN, LOW);
    // Attente de 500 millisecondes
    delay(250);
  }
  etatActuelle = FADE;
}
void fading() {
  Serial.println("Variation - " + STUDENTNUMBER);
  for (int fadeValue = MAXFADE; fadeValue >= MINFADE; fadeValue -= stepOfFading) {
    // sets the value (range from 0 to 255):
    analogWrite(LEDPIN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  etatActuelle = HIGHANDLOW;
}

void highAndLow() {
  Serial.println("Allume - " + STUDENTNUMBER);
  digitalWrite(LEDPIN, LOW);
  // Attente de 500 millisecondes
  delay(250);
  // Extinction de la LED sur la pin 13
  digitalWrite(LEDPIN, HIGH);
  // Attente de 500 millisecondes
  delay(1000);
  digitalWrite(LEDPIN, LOW);
  // Attente de 500 millisecondes
  delay(1000);
  etatActuelle = BLINK;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (etatActuelle) {
    case BLINK:
      blinking();
      break;
    case FADE:
      fading();
      break;
    case HIGHANDLOW:
      highAndLow();
      break;
  }
}
