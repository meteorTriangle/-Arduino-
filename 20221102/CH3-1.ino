int DIP = 50;
int Buzzer = 4;
int LED = 29;

void setup(){
    pinMode(LED, OUTPUT);
    digitalWrite(LED, 1);
    pinMode(Buzzer, OUTPUT);
    digitalWrite(Buzzer, 0);
    Serial.begin(9600);
}


void loop() {
    int dip = digitalRead(DIP);
    if(!dip) {
        Serial.println("指撥開關ON");
    }
    else {
        Serial.println("指撥開關OFF");
    }
    Serial.println();
    if (Serial.available() > 0) {
        char x = Serial.read();
        if (x == 'A' || x == ''a) {
            beep();
            digitalWrite(LED, 0);
            Serial.println("LED亮");
        }
        elif (x == 'B' || x == 'b') {
            beep();
            digitalWrite(LED, 1);
            Serial.println("LED不亮");
        }
    }
    delay(250);
}

void beep() {
    tone(Buzzer, 1000);
    delay(100);
    noTone(Buzzer);
}