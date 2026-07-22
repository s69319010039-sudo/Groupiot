#define RED_LED    D1
#define YELLOW_LED D2
#define GREEN_LED  D6
#define BUTTON     D5

int state = 0;
bool lastButton = HIGH;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  updateLED();
}

void loop() {
  bool currentButton = digitalRead(BUTTON);

  // ตรวจจับการกดปุ่ม
  if (lastButton == HIGH && currentButton == LOW) {
    state++;
    if (state > 2) state = 0;

    updateLED();
    delay(200); // กันเด้ง
  }

  lastButton = currentButton;
}

void updateLED() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  if (state == 0) {
    digitalWrite(RED_LED, HIGH);
  }
  else if (state == 1) {
    digitalWrite(YELLOW_LED, HIGH);
  }
  else if (state == 2) {
    digitalWrite(GREEN_LED, HIGH);
  }
}