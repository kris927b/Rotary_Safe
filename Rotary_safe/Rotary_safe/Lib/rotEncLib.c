#include "rotEncLib.h"

void init_comp(){
    pinMode(B5, OUTPUT, DISABLED); // LED as output
    pinMode(B7, INPUT, ENABLED); // button as input
	pinMode(C0, INPUT, ENABLED);
	pinMode(C1, INPUT, ENABLED);
}

uint8_t read_rot_encoder(){
    uint16_t oldState = readValue(), state = 0;
    while (1){
        state = readValue();
        if (state != oldState){
            if (state == 1 && oldState == 3){ //CCW
                return 0;
            } else if (state == 3 && oldState == 1){ //CW
                return 1;
            }
        }
        oldState = state;
    }
}

void blink_LED(){
    for (uint8_t i = 0; i < 5 ;i++){
        delay(200);
        PORTB |= (1 << PORTB5);
        delay(200);
        PORTB &= ~(1 << PORTB5);
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