#include "darts.h"

double punto( coordinate_t p) {
    return sqrt(pow(p.x,2) + pow(p.y,2));
}
int score(coordinate_t x){
    if( punto(x) > 10 ){
        return 0;
    } else if( punto(x) > 5 ){
        return 1;
    } else if( punto(x) > 1 ){
        return 5;
    } else {
        return 10;
    }
}