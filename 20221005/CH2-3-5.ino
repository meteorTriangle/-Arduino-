int LED[10] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33};
int DIP[4] = {53, 52, 51, 50};
byte sw;

void  setup() {
    for (int i = 0; i < 10; i++){
        pinMode(LED[i], OPUTPUT);
        digitalWrite(LED[1], 1);
    }
}


void loop() {
    sw = 0;
    for(int i = 0; i < 4; i++){
        sw = sw<<1 | digitalRead(DIP[3-i]);
    }

    switch (sw) 
    {
        case 0xE:
            Sweep();
            break;
        case 0xD:
            Happy();
            break;
        case 0xB:
            Wipers();
            break;
        case 0x7:
            Jump();
            break;
        default:
    }
}

void Sweep() {
    for(int i = 0; i < 10; i++){
        digitalWrite(LED[i], 0);
        delay(150);
    }
    delay(250);
    
    for(int i = 0; i < 10; i++){
        digitalWrite(LED[9-i], 0);
        delay(150);
    }
    delay(250);
}

void Happy() {
    for ( int i = 0; i < 5; i++) {
        digitalWrite(LED[4-i], 0);
        digitalWrite(LED[5+i], 0);
        delay(150);
    }
    delay(250);
    for ( int i = 0; i < 5; i++) {
        digitalWrite(LED[i], 0);
        digitalWrite(LED[9-i], 0);
        delay(150);
    }
    delay(250);
}


void Wipers() {
    for ( int i = 0; i < 5; i++) {
        digitalWrite(LED[i], 0);
        digitalWrite(LED[5+i], 0);
        delay(150);
    }
    delay(250);
    for ( int i = 0; i < 5; i++) {
        digitalWrite(LED[4-i], 0);
        digitalWrite(LED[9-i], 0);
        delay(150);
    }
    delay(250);
}


void Jump() {
    for( int i = 0; i < 3; i++){
        digitalWrite(LED[i]. 0);
        digitalWrite(LED[i+3]. 0);
        digitalWrite(LED[i+6]. 0);
        if(i == 0) {
            digitalWrite(LED[9], 0);
        }
        delay(80);
        
        digitalWrite(LED[i]. 1);
        digitalWrite(LED[9]. 1);
        digitalWrite(LED[i+3]. 1);
        digitalWrite(LED[i+6]. 1);
    }

}