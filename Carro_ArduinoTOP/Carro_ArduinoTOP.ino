const int motorA1  = 9;   
const int motorA2  = 3;    
const int motorB1  = 11;    
const int motorB2  = 10;  
const int motorENA = 6;    
const int motorENB = 5;
const int buzzer = 13 ;   

const int BTState = 2;   

int i = 0;
int j = 0;
int state_rec;
int vSpeed = 200; 
char state;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(BTState, INPUT);
  pinMode(motorENA, OUTPUT);
  pinMode(motorENB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BTState) == LOW) {
    state_rec = 'S';
  }
  if (Serial.available() > 0) {
    state_rec = Serial.read();
    state = state_rec;
    //   Serial.println(vSpeed);
  }
  if (state == '0') {
    vSpeed = 0;
  }
  else if (state == '4') {
    vSpeed = 100;
  }
  else if (state == '6') {
    vSpeed = 155;
  }
  else if (state == '7') {
    vSpeed = 180;
  }
  else if (state == '8') {
    vSpeed = 200;
  }
  else if (state == '9') {
    vSpeed = 230;
  }
  else if (state == 'q') {
    vSpeed = 255;
  }

  if (state != 'S') {
    Serial.print(state);
  }
  if (state == 'F') {
    analogWrite(motorENA, vSpeed);
    analogWrite(motorENB, vSpeed);
    analogWrite(motorB1, vSpeed);
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB2, 0);
  }

  else if (state == 'I') {  
    analogWrite(motorENA, vSpeed);
    analogWrite(motorENB, vSpeed);
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 100);
    analogWrite(motorB2, 0);
  }

  else if (state == 'G') {  
    analogWrite(motorENA, vSpeed);
    analogWrite(motorENB, vSpeed);
    analogWrite(motorA1, 100);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed);
    analogWrite(motorB2, 0);
  }

  else if (state == 'B') { 
    analogWrite(motorENA, vSpeed);
    analogWrite(motorENB, vSpeed);
    analogWrite(motorA1, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
    analogWrite(motorA2, vSpeed);
  }

  else if (state == 'H') { 
    analogWrite(motorENA, vSpeed);
    analogWrite(motorENB, vSpeed);
    analogWrite(motorA1, 0);
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 100);
  }

  else if (state == 'J') {  
    analogWrite(motorENA, vSpeed);
    analogWrite(motorENB, vSpeed);
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 100);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
  }

  else if (state == 'L') {  
    analogWrite(motorENA, vSpeed);
    analogWrite(motorENB, vSpeed);
    analogWrite(motorA1, 0);
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, vSpeed);
    analogWrite(motorB2, 0);
  }
  else if (state == 'R') {  
    analogWrite(motorENA, vSpeed);
    analogWrite(motorENB, vSpeed);
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
  }
  else if (state == 'S') {  
    analogWrite(motorENA, vSpeed);
    analogWrite(motorENB, vSpeed);
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
  }


  else if (state == 'V') {
    if (j == 0) {
      tone(buzzer, 1000);
      j = 1;
    }
    else if (j == 1) {
      noTone(buzzer);
      j = 0;
    }
    state = 'n';
  }


}
