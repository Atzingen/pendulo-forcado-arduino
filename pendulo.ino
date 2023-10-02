#include <Servo.h>

Servo pendulo;  

int pos = 0;    
int dt = 500;
int delta_angulo = 30;
int servo_pin = 9;

void setup() {
  Serial.begin(9600);
  pendulo.attach(servo_pin); 
}

void loop() {
  unsigned long t0 = millis();

  pendulo.write(90 - delta_angulo);
  delay(dt);
  pendulo.write(90 + delta_angulo);
  delay(dt);

  Serial.print("Período = ");
  Serial.println(millis() - t0);
  if (Serial.available() > 0){
    int serial_data = Serial.readString().toInt();
    dt = serial_data/(2);
    Serial.print("new: ");
    Serial.println(dt);
  }
}












