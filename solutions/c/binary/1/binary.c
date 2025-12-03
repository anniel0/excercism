#include "binary.h"

int convert(const char *input) {
    int index = strlen(input),suma = 0,j = 0;
    for( int i = index-1 ; i >= 0 ;i-- ){
        if( input[i] == '1' ){
            suma += (int)pow(2,j);
        } else if( input[i] != '1' && input[i] != '0' ){
            return -1;
        }
        j++;
    }
    return suma;
}