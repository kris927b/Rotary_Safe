void init_comp(){
    DDRB |= (1 << DDB5); // LED as output
    DDRB &= ~(1 << DDB7); // button as input
}

uint8_t read_rot_encoder(){
    static uint16_t oldState = readValue(), state = 0;
    state = readValue();
    if (state != oldState){
        if (state == 1 && oldState == 3){ //CCW
            return 0;
        } else if (state == 3 && oldState == 1){ //CW
            return 1;
        }
    }
    oldState == state;
}

void blink_LED(){
    for (uint8_t i = 0; i < 5 ;i++){
        delay(200);
        PORTB |= (1 << PORTB5);
        delay(200);
        PORTB &= (1 << PORTB5);
    }
}

uint8_t readValue(){
    uint8_t res = 0;
    if (PINC & (1 << PINC0))
        res |= (1 << 1);
    if (PINC & (1 << PINC1))
        res |= (1 << 0);
    return res;
}