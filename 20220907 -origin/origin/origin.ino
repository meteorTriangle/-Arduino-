#define button_on 47
#define button_off 46
#define buzzer 4
#define LED 24

void setup() {
  // put your setup code here, to run once:
  pinMode(button_on, INPUT);
  pinMode(button_off, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(button_on) || !digitalRead(button_off)) {
    tone(buzzer, 523);
  }
  else {
    noTone(buzzer);
  }

  if (!digitalRead(button_on)) {
    digitalWrite(LED, 1);

  }
  if (!digitalRead(button_off)) {
    digitalWrite(LED, 0);

  }

  Serial.println(digitalRead(button_on));

  delay(2);

}
