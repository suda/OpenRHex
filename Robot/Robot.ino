SYSTEM_MODE(MANUAL);

int leftValue;
int rightValue;

Servo leftServo1;
Servo leftServo2;
Servo leftServo3;

Servo rightServo1;
Servo rightServo2;
Servo rightServo3;

TCPServer server = TCPServer(8080);
TCPClient client;

void setServos() {
  leftServo1.write(leftValue);
  leftServo2.write(leftValue);
  leftServo3.write(leftValue);

  rightServo1.write(rightValue);
  rightServo2.write(rightValue);
  rightServo3.write(rightValue - 5);
}

void setup() {
  WiFi.on();
  WiFi.connect();

  leftServo1.attach(A7);
  leftServo2.attach(A4);
  leftServo3.attach(A5);

  rightServo1.attach(D1);
  rightServo2.attach(D0);
  rightServo3.attach(A1);

  leftValue = 95;
  rightValue = 95;
  setServos();

  pinMode(D7, OUTPUT);
  digitalWrite(D7, LOW);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    leftValue = Serial.read();
    rightValue = Serial.read();
    setServos();
  }

  if (client.connected()) {
    if (client.available()) {
      leftValue = client.read();
      rightValue = client.read();
      setServos();
    }
  } else {
    client = server.available();
  }
}
