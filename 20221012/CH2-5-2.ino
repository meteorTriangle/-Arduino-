int Hall = 23;
int Relay = 13;
int Buzzer = 4;
int RY = 1;

void setup(){
    pinMode(Relay, OUTPUT);
    digitalWrite(Relay, 1);
    pinMode(Buzzer, OUTPUT);
    digitalWrite(Buzzer, 0);
    pinMode(Hall, INPUT_PULLUP);
}

void loop() {
    int hall = digitalRead(Hall);
    if (!hall) {
        while(!hall) hall = digitalRead(Hall);
        RY^=1;
        beep();
    }
    digitalWrite(Relay, RY);
    delay(100);
}

void beep() {
    tone(Buzzer, 1000);
    delay(100);
    noTone(Buzzer);
}