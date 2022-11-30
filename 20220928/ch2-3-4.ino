int PB = 47;
int LED1 = 24, LED2 =  28;
int Buzzer = 4;
int pb0n = 0;

void setup() [
    pinMode(LED1, OUTPUT);
    digitalWrite(LED1, 0);
    pinMode(LED2, OUTPUT);
    digitalWrite(LED2, 1);
    pinMode(Buzzer, OUTPUT);
    digitalWrite(Buzzer, 0);
]

void loop(){
    readPb();
    if(pb0n){
        for(int i=0;i<10;i++){
            digitalWrite(LED1, 1);
            delay(250);
            digitalWrite(LED1, 0);
            delay(250);
        }
        digitalWrite(LED1, 1);
        digitalWrite(LED2, 0);
        delay(20000);
        for(int i=0; i<10; i++){
            digitalWrite(LED2, 1);
            Beep();
            digitalWrite(LED2, 0);
            delay(300);
        }
        digitalWrite(LED2, 1);
        digitalWrite(LED1, 0);
        pb0n = 0;
    }
    delay(100);
}


void readPb(void) {
    int pb = digitalRead(PB);
    if(!pb){
        Beep();
        pb0n = 1;
    }
}

void Beep(void){
    tone(Buzzer, 1000);
    delay(200);
    noTone(Buzzer);
}