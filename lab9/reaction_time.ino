const int LED_PIN = 12;
const int BUTTON_PIN = 7;

bool button_pressed() {
  return digitalRead(BUTTON_PIN) == HIGH;
}

bool game_delay() {
  unsigned long waitTime = random(3000, 5000);
  unsigned long start = millis();

  while (millis() - start < waitTime) {
    if (button_pressed()) return false;
  }

  return true;
}

void reaction_time() {
  digitalWrite(LED_PIN, HIGH);

  while (digitalRead(LED_PIN) == HIGH) {
    if (button_pressed()) digitalWrite(LED_PIN, LOW);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);
  randomSeed(1);
}

void loop() {
  while (!game_delay()) {
    Serial.println("Please stop cheating :(");
    delay(500);
  }

  delay(random(3000, 5000));

  unsigned long t1 = millis();
  reaction_time();
  unsigned long t2 = millis();

  Serial.println("Your reaction time was: ");
  Serial.println(t2 - t1);
  Serial.println(" milliseconds")

  Serial.println("Let's try again.");
  delay(500);
}
