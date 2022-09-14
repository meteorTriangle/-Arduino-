#define button_on 47
#define buzzer 4
int LED[10] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33};
bool pili_state = false;
bool last_pili_state = false;
int pili_flash_period = 70;
long last_millis;
int pili_count = 0;
bool pili_dir = 0;
bool last_button_state = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(button_on, INPUT);
  pinMode(buzzer, OUTPUT);
  for (int i = 0; i < 10; i++) {
    pinMode(LED[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool sw = !digitalRead(button_on);
  if (sw) {
    tone(buzzer, 523);
  }
  else {
    noTone(buzzer);
  }
  if (sw && !last_button_state){
    pili_count = -1;
    pili_dir = 0;
    last_millis = millis();
    pili_state = !pili_state;
  }

  uint16_t pilis_light;
  if (pili_state) {
    bool LED_change = (millis() - last_millis) > pili_flash_period;
    if ((pili_count == -1) || LED_change) {
      pili_count++;
      if (pili_count >= 10) {
        pili_count = 0;
        pili_dir ^= 1;
      }
      if (~pili_dir) {
        pilis_light = 0b0000000001 << pili_count;
      }
      if (pili_dir) {
        pilis_light = 0b1000000000 >> pili_count;
      }
      last_millis = millis();
    }
  }
  else{
    pilis_light=0;
  }
    for (int i = 0; i < 10; i++) {
      digitalWrite(LED[i], !(0b000000001 & (pilis_light >> i)));
    }
  delay(2);
  last_pili_state = pili_state;
  last_button_state = sw;
}
