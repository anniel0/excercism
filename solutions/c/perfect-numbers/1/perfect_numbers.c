#include "perfect_numbers.h"

kind classify_number(int n) {
    if (n <= 0) {
        return ERROR;
    }
    
    if (n == 1) {
        return DEFICIENT_NUMBER;
    }
    
    int sum = 0;
    
    // Buscar divisores hasta la raiz cuadrada de n
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            
            // Añadir el divisor complementario si es diferente
            if (i != 1 && i != n / i) {
                sum += n / i;
            }
        }
    }
    
    if (sum == n) {
        return PERFECT_NUMBER;
    } else if (sum > n) {
        return ABUNDANT_NUMBER;
    } else {
        return DEFICIENT_NUMBER;
    }
}