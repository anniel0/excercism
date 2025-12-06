#include "sum_of_multiples.h"


unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit) {
    if (factors == NULL || number_of_factors == 0) {
        return 0;
    }
    
    unsigned int total_sum = 0;
    
    // Para cada numero del 1 al límite-1
    for (unsigned int num = 1; num < limit; num++) {
        for (size_t i = 0; i < number_of_factors; i++) {
            // Verificar que el factor no sea 0
            if (factors[i] != 0 && num % factors[i] == 0) {
                total_sum += num;
                break; // No necesitamos verificar otros factores
            }
        }
    }
    
    return total_sum;
}