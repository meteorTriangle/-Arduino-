int PB = 47;
int buzzer = 4 ;
int LED[10] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33};
int sw = 0;

void setup(){
    pinMode(Buzzer, OUTPUT);
    digitalWrite(Buzzer, 0);
    for(int i = 0; i<10; i++){
        pinMode(LED[i], OUTPUT);
        digitalWrite(LED[i], 1);
    }

}

void loop(){
    int pd = digitalRead(PB);
    if(!pb){
        tone(Buzzer, 1000);
        sw = !sw;
        delay(100);
        noTone(Buzzer);
    }
    while(sw){
        for(int i = 0; i<10; i++){
            digitalWrite(LED[i], 0);
            delay(150);
            pb = digitalRead(PB);
            if(!pb) {
                tone(Buzzer, 1000);
                sw = !sw;
                delay(100);
                noTone(Buzzer);
            }
        }
        for(int i = 0; i<10; i++){
            digitalWrite(LED[9-i], 0);
            delay(150);
            digitalWrite(LED[9-i], 1);
            pb = digitalRead(PB);
            if(!pb) {
                tone(Buzzer, 1000);
                sw = !sw;
                delay(100);
                noTone(Buzzer);
            }
        }
    }
}