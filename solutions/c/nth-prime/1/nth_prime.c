#include "nth_prime.h"

static bool es_primo(uint32_t n ) {
    uint32_t sum = 0;
    for( uint32_t i = 1; i <= n ;i++ ){
        if( n % i == 0 ){
            sum++;
        }
    }
    if( sum == 2 ){
        return true;
    } else {
        return false;
    }
}
uint32_t nth(uint32_t n) {
    if (n == 0) return 0;
    
    uint32_t count = 0;
    uint32_t candidate = 2;
    
    while (count < n) {
        if (es_primo(candidate)) {
            count++;
            if (count == n) {
                return candidate;
            }
        }
        candidate++;
    }
    return 0; 
}