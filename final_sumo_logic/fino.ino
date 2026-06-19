
void stopMotors() {
  analogWrite(LEFT_RPWM, 0);
  analogWrite(LEFT_LPWM, 0);
  analogWrite(RIGHT_RPWM, 0);
  analogWrite(RIGHT_LPWM, 0);
}

void left() {
  analogWrite(LEFT_RPWM, 200);
  analogWrite(LEFT_LPWM, 0);

  analogWrite(RIGHT_RPWM, 200);
  analogWrite(RIGHT_LPWM, 0);
}

void right() {
  analogWrite(LEFT_RPWM, 0);
  analogWrite(LEFT_LPWM, 200);

  analogWrite(RIGHT_RPWM, 0);
  analogWrite(RIGHT_LPWM, 200);
}

void forward() {
  analogWrite(LEFT_RPWM, 0);
  analogWrite(LEFT_LPWM, 200);

  analogWrite(RIGHT_RPWM, 200);
  analogWrite(RIGHT_LPWM, 0);
}

void backward () {
  analogWrite(LEFT_RPWM, 200);
  analogWrite(LEFT_LPWM, 0);

  analogWrite(RIGHT_RPWM, 0);
  analogWrite(RIGHT_LPWM, 200);
}
void attack() {
  analogWrite(LEFT_RPWM, 0);
  analogWrite(LEFT_LPWM, 255);

  analogWrite(RIGHT_RPWM, 255);
  analogWrite(RIGHT_LPWM, 0);
}

