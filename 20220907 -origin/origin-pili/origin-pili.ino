#define button_on 47
#define button_off 46
#define buzzer 4
int LED[8] = {24, 25, 26, 27, 28, 29, 30, 31};
bool pili_state = false;
int pili_flash_period = 70;
int last_millis;
int pili_count = 0;
bool pili_dir = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button_on, INPUT);
  pinMode(button_off, INPUT);
  pinMode(buzzer, OUTPUT);
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
  }
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
    pili_state = 1;
    pili_count = -1;
    pili_dir = 0;
    last_millis = millis();

  }
  if (!digitalRead(button_off)) {
    pili_state = 0;
  }
  uint8_t pilis_light;
  if (pili_state) {
    bool LED_change = (millis() - last_millis) > pili_flash_period;
    if ((pili_count == -1) || LED_change) {
      pili_count++;
      if (pili_count >= 8) {
        pili_count = 0;
        pili_dir ^= 1;
      }
      if (~pili_dir) {
        pilis_light = 0b00000001 << pili_count;
      }
      if (pili_dir) {
        pilis_light = 0b10000000 >> pili_count;
      }
      last_millis = millis();
    }
  }
  else{
    pilis_light=0;
  }
    for (int i = 0; i < 8; i++) {
      digitalWrite(LED[i], !(0b00000001 & (pilis_light >> i)));
    }

  delay(2);

}
