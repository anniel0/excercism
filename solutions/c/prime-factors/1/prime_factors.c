#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
    uint64_t j = 0,i= 2;
    size_t num = 0;
    while( n != 1 ) {
        if( n % i == 0) {
            factors[j] = i;
            j++;
            n /= i;
            num++;
        } else {
            i++;
        }
    }
    return num;
}
