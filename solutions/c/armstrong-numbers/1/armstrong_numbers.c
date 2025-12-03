#include "armstrong_numbers.h"

int number_digit(int n) {
    if( n == 0 ) {
        return 0;
    } else {
        return 1 + number_digit(n/10);
    }
}
bool is_armstrong_number(int candidate) {
    if( candidate < 0 ) {
        return false;
    }
    int numberDigit = number_digit(candidate),sum = 0,aux = candidate ; 

    for( int i = 0 ; i < numberDigit ;i++ ){
           sum += (int)pow(aux % 10,numberDigit);
           aux /= 10;
    }
    if( sum == candidate ) {
        return true;
    } else {
        return false;
    }
}