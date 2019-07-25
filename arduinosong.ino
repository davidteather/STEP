/* Note library for Arduino song and light show */

#include <Arduino.h>

float beat = 434.78; //quarter note

float c0 = 16.35;
float cs0 = 17.32;
float d0 = 18.35;
float ds0 = 19.45;
float e0 = 20.60;
float f0 = 21.83;
float fs0 = 23.12;
float g0 = 24.50;
float gs0 = 25.96;
float a0 = 27.50;
float as0 = 29.14;
float b0 = 30.87;
float c1 = 32.70;
float cs1 = 34.65;
float d1 = 36.71;
float ds1 = 38.89;
float e1 = 41.20;
float f1 = 43.65;
float fs1 = 46.25;
float g1 = 49.00;
float gs1 = 51.91;
float a1 = 55.00;
float as1 = 58.27;
float b1 = 61.74;
float c2 = 65.41;
float cs2 = 69.30;
float d2 = 73.42;
float ds2 = 77.78;
float e2 = 82.41;
float f2 = 87.31;
float fs2 = 92.50;
float g2 = 98.00;
float gs2 = 103.83;
float a2 = 110.00;
float as2 = 116.54;
float b2 = 123.47;
float c3 = 130.81;
float cs3 = 138.59;
float d3 = 146.83;
float ds3 = 155.56;
float e3 = 164.81;
float f3 = 174.61;
float fs3 = 185.00;
float g3 = 196.00;
float gs3 = 207.65;
float a3 = 220.00;
float as3 = 233.08;
float b3 = 246.94;
float c4 = 261.63;
float cs4 = 277.18;
float d4 = 293.66;
float ds4 = 311.13;
float e4 = 329.63;
float f4 = 349.23;
float fs4 = 369.99;
float g4 = 392.00;
float gs4 = 415.30;
float a4 = 440.00;
float as4 = 466.16;
float b4 = 493.88;
float c5 = 523.25;
float cs5 = 554.37;
float d5 = 587.33;
float ds5 = 622.25;
float e5 = 659.26;
float f5 = 698.46;
float fs5 = 739.99;
float g5 = 783.99;
float gs5 = 830.61;
float a5 = 880.00;
float as5 = 932.33;
float b5 = 987.77;
float c6 = 1046.50;
float cs6 = 1108.73;
float d6 = 1174.66;
float ds6 = 1244.51;
float e6 = 1318.51;
float f6 = 1396.91;
float fs6 = 1479.98;
float g6 = 1567.98;
float gs6 = 1661.22;
float a6 = 1760.00;
float as6 = 1864.66;
float b6 = 1975.53;
float c7 = 2093.00;
float cs7 = 2217.46;
float d7 = 2349.32;
float ds7 = 2489.02;
float e7 = 2637.02;
float f7 = 2793.83;
float fs7 = 2959.96;
float g7 = 3135.96;
float gs7 = 3322.44;
float a7 = 3520.00;
float as7 = 3729.31;
float b7 = 3951.07;
float c8 = 4186.01;
float cs8 = 4434.92;
float d8 = 4698.64;
float ds8 = 4978.03;
float e8 = 5274.04;
float f8 = 5587.65;
float fs8 = 5919.91;
float g8 = 6271.93;
float gs8 = 6644.88;
float a8 = 7040.00;
float as8 = 7458.62;
float b8 = 7902.13;

// vars
int G = 2;
int F = 3;
int A = 4;
int B = 5;

int E = 6;
int D = 7;
int C = 8;

int buzzerPin = 13;

void setToLow() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void countDown() {
  
  //pseudo-12
  delay(beat);

  // 11
  digitalWrite(F, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);

  delay(beat);

  setToLow();

  // 10
  digitalWrite(D, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);

  delay(beat);
  setToLow();


  // 9
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);


  delay(beat);
  setToLow();

  // 8
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  delay(beat);
  setToLow();

  // 7
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);

  delay(beat);
  setToLow();

  // 6
  digitalWrite(A, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);


  delay(beat);
  setToLow();
  
  // 5
  digitalWrite(A, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);


  delay(beat);
  setToLow();

  // 4
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  delay(beat);
  setToLow();

  // 3
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(G, HIGH);

  delay(beat);
  setToLow();

  // 2
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, HIGH);

  delay(beat);
  setToLow();

  // 1
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);


  delay(beat);
  setToLow();
}

void playNote(float multiplier, float frequency, int led, int led2) {
  tone(buzzerPin, frequency, (beat * multiplier) - 10);
  digitalWrite(led, HIGH);
  digitalWrite(led2, HIGH);
  delay(beat * multiplier);
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  delay(10);
}

void playSong() {
  float as4 = 466.16;
  // Line 1
  // 0
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  playNote(0.5, c5, 9, 12);
  setToLow();
  playNote(1.0, c5, 10, 11);
  playNote(1.0, c5, 9, 12);
  playNote(3.0, c5, 10, 11);
  playNote(0.5, cs5, 9, 12);
  playNote(2.5, 466.16, 10, 11);

  delay(beat * 0.5);

  playNote(1.0, 466.16, 9, 12);
  playNote(0.5, gs4, 10, 11);
  playNote(1.0, 466.16, 9, 12);
  playNote(0.5, 466.16, 10, 11);
  playNote(0.5, gs4, 9, 12);
  playNote(1.0, c5, 10, 11);
  playNote(0.5, ds4, 9, 12);
  playNote(1.0, f4, 10, 11);

  // Line 2
  playNote(0.5, c5, 10, 12);
  playNote(0.5, c5, 9, 10);
  playNote(0.5, c5, 10, 12);
  playNote(0.5, c5, 9, 11);
  playNote(0.5, c5, 11, 12);
  playNote(1.0, c5, 9, 10);
  playNote(3.0, c5, 10, 12);
  playNote(0.5, cs5, 9, 12);
  playNote(2.5, 466.16, 11, 12);
  
  delay(beat * 0.5);

  playNote(1.0, 466.16, 10, 11);
  playNote(0.5, gs4, 9, 10);
  playNote(1.0, 466.16, 11, 12);
  playNote(1.0, 466.16, 9, 10);
  playNote(1.0, 466.16, 11, 12);
  playNote(0.5, c5, 9, 10);
  playNote(0.5, gs4, 11, 12);
  playNote(0.5, g4, 9, 10);
  playNote(1.0, f4, 9, 12);

  delay(beat * 1.5);
  // chorus
  playNote(0.5, ds5, 9, 11);
  playNote(1.0, f5, 10, 12);
  playNote(1.0, f5, 9, 11);
  playNote(0.5, f5, 10, 12);
  playNote(0.5, ds5, 9, 11);
  playNote(0.5, f5, 9, 10);
  playNote(1.5, ds5, 11, 12);
  playNote(0.5, 466.16, 9, 10);
  playNote(1.0, c5, 9, 12);
  playNote(1.5, cs5, 10, 11);
  
  playNote(1.0, ds5, 9, 0);
  playNote(1.0, ds5, 10, 0);
  playNote(0.5, ds5, 11, 0);
  playNote(0.5, c5, 12, 0);
  playNote(0.5, ds5, 11, 0);
  playNote(1.5, c5, 10, 0);
  playNote(0.5, f4, 9, 0);
  playNote(1.0, g4, 11, 12);
  playNote(1.5, gs4, 9, 10);

  playNote(1.0, f5, 9, 0);
  playNote(1.0, f5, 10, 0);
  playNote(0.5, f5, 11, 0);
  playNote(0.5, ds5, 12, 0);
  playNote(0.5, f5, 11, 0);
  playNote(1.5, ds5, 10, 0);
  playNote(0.5, 466.16, 9, 0);
  playNote(1.0, c5, 11, 10);
  playNote(1.0, cs5, 12, 9);
  playNote(0.5, c5, 10, 11);

  playNote(0.5, ds5, 9, 0);
  playNote(0.5, c5, 10, 0);
  playNote(1.0, ds5, 11, 0);
  playNote(0.5, ds5, 12, 0);
  playNote(0.5, c5, 11, 0);
  playNote(0.5, ds5, 10, 0);
  playNote(1.0, c5, 9, 0);
  playNote(0.5, f4, 11, 12);
  playNote(0.5, f4, 9, 10);
  playNote(1.0, g4, 11, 12);
  playNote(1.5, gs4, 9, 10);


  playNote(1.0, f5, 9, 11);
  playNote(1.0, f5, 10, 12);
  playNote(0.5, f5, 9, 11);
  playNote(0.5, ds5, 12, 10);
  playNote(0.5, f5, 9, 0);
  playNote(1.0, g5, 10, 0);
  playNote(1.0, g5, 11, 0);
  playNote(2.0, g5, 12, 0);

  delay(beat * 0.5);

  playNote(1.0, ds5, 9, 0);
  playNote(1.0, ds5, 10, 0);
  playNote(1.0, ds5, 11, 0);
  playNote(0.5, ds5, 12, 0);
  playNote(0.5, c5, 11, 0);
  playNote(0.5, cs5, 10, 0);
  playNote(1.5, c5, 9, 0);
  playNote(0.5, c5, 9, 10);
  playNote(0.5, c5, 11, 12);
  playNote(0.5, c5, 9, 12);
  playNote(2.5, c5, 10, 11);

  delay(beat * 0.5);
  
  playNote(1.0, cs5, 11, 10);
  playNote(2.5, 466.16, 9, 12);

  delay(beat * 0.5);

  playNote(0.5, gs4, 9, 0);
  playNote(0.5, g4, 10, 0);
  playNote(0.5, gs4, 11, 0);
  playNote(0.5, g4, 12, 0);
  playNote(1.5, g4, 11, 0);
  playNote(1.0, c5, 10, 0);
  playNote(0.5, g4, 9, 0);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  playNote(2.5, gs4, 0, 0);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  


  // 3rd line
  
}

void setup() {

  // LED
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  // Pins
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);


  pinMode(buzzerPin, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  countDown();
  playSong();
  // put your main code here, to run repeatedly:
    
}
