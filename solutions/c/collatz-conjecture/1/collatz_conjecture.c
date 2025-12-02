#include "collatz_conjecture.h"

int steps(int start) {
    if( start < 0) {
        return -1;
    }
    
    if( start == 0 ) {
        return -1;
    } else if( start == 1 ) {
        return 0;
    } else {
        if( start % 2 == 0 ){
            return 1 + steps(start / 2);
        } else {
            return 1 + steps( start * 3 +1 );
        }
    }
}