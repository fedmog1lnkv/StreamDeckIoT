#include "SoftwareSerial.h"
#include "GyverEncoder.h"

#define BUTTON_PIN 2

#define BUTTON_1 4
#define BUTTON_2 5
#define BUTTON_3 6
#define BUTTON_4 7
#define BUTTON_5 12
#define BUTTON_6 11

#define ENCODER_1_L 8
#define ENCODER_1_R 9
#define ENCODER_1_C 10

#define BOUNCE_TIME 500
#define ENCODER_DELTA 20

#define ENCODER_STEP 5
#define ENCODER_MAX 100
#define ENCODER_MIN 0



unsigned long now = 0;

unsigned long last_pressed_1 = 0;
unsigned long last_pressed_2 = 0;
unsigned long last_pressed_3 = 0;
unsigned long last_pressed_4 = 0;
unsigned long last_pressed_5 = 0;
unsigned long last_pressed_6 = 0;

SoftwareSerial BTserial(1, 0);


Encoder enc_1(ENCODER_1_C, ENCODER_1_R, ENCODER_1_L);

bool encoder_mod = true;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  pinMode(BUTTON_6, INPUT_PULLUP);
  pinMode(ENCODER_1_L, INPUT_PULLUP);
  pinMode(ENCODER_1_R, INPUT_PULLUP);

  enc_1.setType(TYPE1);

  Serial.begin(9600);
  BTserial.begin(9600);
}

int val_1 = LOW;
int val_2 = LOW;
int val_3 = LOW;
int val_4 = LOW;
int val_5 = LOW;
int val_6 = LOW;


int last_state_1 = LOW;
int last_state_2 = LOW;
int last_state_3 = LOW;
int last_state_4 = LOW;
int last_state_5 = LOW;
int last_state_6 = LOW;

int encoder_val_1 = 50;
int encoder_val_2 = -1;
int last_encoder_val_1 = -1;
int last_encoder_val_2 = -1;

int rotarValue = 0;


bool have_processing = true;


void loop() {
  val_1 = digitalRead(BUTTON_1);
  val_2 = digitalRead(BUTTON_2);
  val_3 = digitalRead(BUTTON_3);
  val_4 = digitalRead(BUTTON_4);
  val_5 = digitalRead(BUTTON_5);
  val_6 = digitalRead(BUTTON_6);

  enc_1.tick();

  now = millis();

  if (val_1 == HIGH && now - last_pressed_1 > BOUNCE_TIME && val_1 != last_state_1 && !have_processing) {
    have_processing = true;
    BTserial.write(1);
    Serial.println(1);
    // Serial.println(now);
    // Serial.println(last_pressed_1);
    last_pressed_1 = now;
    // Serial.println("pressed 1 button");
  }

  if (val_2 == HIGH && now - last_pressed_2 > BOUNCE_TIME && val_2 != last_state_2 && !have_processing) {
    have_processing = true;
    Serial.println(2);
    // Serial.println(now);
    // Serial.println(last_pressed_2);
    last_pressed_2 = now;
    // Serial.println("pressed 2 button");
  }

  if (val_3 == HIGH && now - last_pressed_3 > BOUNCE_TIME && val_3 != last_state_3 && !have_processing) {
    have_processing = true;
    Serial.println(3);
    // Serial.println(now);
    // Serial.println(last_pressed_3);
    last_pressed_3 = now;
    // Serial.println("pressed 3 button");
  }

  if (val_4 == HIGH && now - last_pressed_4 > BOUNCE_TIME && val_4 != last_state_4 && !have_processing) {
    have_processing = true;
    Serial.println(4);
    // Serial.println(now);
    // Serial.println(last_pressed_4);
    last_pressed_4 = now;
    // Serial.println("pressed 4 button");
  }

  if (val_5 == HIGH && now - last_pressed_5 > BOUNCE_TIME && val_5 != last_state_5 && !have_processing) {
    have_processing = true;
    Serial.println(5);
    // Serial.println(now);
    // Serial.println(last_pressed_5);
    last_pressed_5 = now;
    // Serial.println("pressed 5 button");
  }

  if (val_6 == HIGH && now - last_pressed_6 > BOUNCE_TIME && val_6 != last_state_6 && !have_processing) {
    have_processing = true;
    Serial.println(6);
    // Serial.println(now);
    // Serial.println(last_pressed_6);
    last_pressed_6 = now;
    // Serial.println("pressed 6 button");
  }

  if (enc_1.isClick()){
      encoder_mod = !encoder_mod;
    }

  if (enc_1.isTurn()) {
    if (enc_1.isRight() && encoder_val_1 + ENCODER_STEP <= ENCODER_MAX) {
      encoder_val_1 += ENCODER_STEP;
    }
    if (enc_1.isLeft() && encoder_val_1 - ENCODER_STEP >= ENCODER_MIN){
      encoder_val_1 -= ENCODER_STEP;
    }


    if (encoder_mod) {
      Serial.println(1000 + encoder_val_1);
    } else {
      Serial.println(2000 + encoder_val_1);
    }
    
  }

  have_processing = false;
  
  last_state_1 = val_1;
  last_state_2 = val_2;
  last_state_3 = val_3;
  last_state_4 = val_4;
  last_state_5 = val_5;
  last_state_6 = val_6;
  
}
