int pirmotionPin = 2;  // Pin of IR Motion Sensor
int pirmotionPin1 = 3; //Pin of IR Motion Sensor 2
int relayPin = 8;  // Pin of Relay Module
int stat = 0;
int timer = 0;
void startSystem();
void startTimer();

void setup() {
  Serial.begin(9600);
  pinMode(pirmotionPin, INPUT);
  pinMode(pirmotionPin1, INPUT);
  pinMode(relayPin, OUTPUT);  // Set Pin connected to Relay as an OUTPUT
  digitalWrite(relayPin, LOW);  // Set Pin to LOW to turn RELAY ON
  attachInterrupt(digitalPinToInterrupt(pirmotionPin), startSystem, HIGH);
  attachInterrupt(digitalPinToInterrupt(pirmotionPin1), startSystem, HIGH);

}

void loop() {


  if (stat == 1) {
    if (digitalRead(pirmotionPin) == HIGH || digitalRead(pirmotionPin1) == HIGH) {  // If Motion is detected
      digitalWrite(relayPin, LOW);  // Turn Relay ON
      Serial.println("Relay is ON");
      startTimer();
      delay(500);
    }
    stat = 0;
  }

  else {
    digitalWrite(relayPin, HIGH);  // Turn Relay OFF
    Serial.println("Relay is OFF");
    delay(500);
  }
}

void startSystem() {
  stat = 1;
  timer = 0;
}
void startTimer() {

  for (timer = 0; timer  < 120; timer++) {

    Serial.print("1 - ");
    Serial.println(digitalRead(pirmotionPin));
    Serial.print("2 - ");
    Serial.println(digitalRead(pirmotionPin1));
    Serial.println(timer);
    delay(100);
  }
}
