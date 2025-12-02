#include "grains.h"

uint64_t square(uint8_t index) {
    uint64_t suma = 0;
    for(uint8_t i = 1; i <= index ; i++ ) {
        if( i == 1 ) {
            suma += 1;
        } else {
            suma += suma;
        }
    }
    return suma;
}
uint64_t total(void) {
    uint64_t suma = 0;
    for(uint8_t i = 1; i <= 64 ; i++ ) {
        suma += square(i);
    }
    return suma;
}