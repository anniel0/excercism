#include "all_your_base.h"

size_t rebase(int8_t digits[], int16_t input_base, int16_t output_base, size_t input_length) {
    if( input_length == 0 ){
        return 0;
    }
    // Validate bases
    if (input_base < 2 || output_base < 2) {
        return 0;
    }
    
    // Validate digits
    for (size_t i = 0; i < input_length; i++) {
        if (digits[i] < 0 || digits[i] >= input_base) {
            return 0;
        }
    }
    
    // Convert to decimal (or some intermediate representation)
    uint64_t value = 0;
    for (size_t i = 0; i < input_length; i++) {
        value = value * input_base + digits[i];
    }
    
    // Special case for zero
    if (value == 0) {
        digits[0] = 0;
        return 1;
    }
    
    // Convert to output base
    size_t pos = 0;
    while (value > 0) {
        digits[pos++] = value % output_base;
        value /= output_base;
    }
    
    // Reverse digits
    for (size_t i = 0; i < pos / 2; i++) {
        int8_t temp = digits[i];
        digits[i] = digits[pos - 1 - i];
        digits[pos - 1 - i] = temp;
    }
    
    return pos;
}