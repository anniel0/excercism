#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    int longit1 = strlen(lhs) , longit2 = strlen(rhs);
    if( longit1 != longit2 ){
        return -1;
    }
    int cantidad = 0;
    for( int i= 0; i < longit1 ;i++ ){
        if( lhs[i] != rhs[i] ) {
            cantidad++;
        }
    }
    return cantidad;
}