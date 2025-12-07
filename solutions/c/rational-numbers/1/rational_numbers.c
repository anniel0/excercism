#include "rational_numbers.h"
#include <math.h>
#include <stdlib.h>

// Función auxiliar para calcular el máximo común divisor
int16_t gcd(int16_t a, int16_t b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int16_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

rational_t reduce(rational_t r) {
    if (r.numerator == 0) {
        r.denominator = 1;
        return r;
    }
    
    int16_t divisor = gcd(r.numerator, r.denominator);
    rational_t result = {
        r.numerator / divisor,
        r.denominator / divisor
    };
    
    // Asegurar que el denominador sea positivo
    if (result.denominator < 0) {
        result.numerator = -result.numerator;
        result.denominator = -result.denominator;
    }
    
    return result;
}

rational_t add(rational_t r1, rational_t r2) {
    rational_t result = {
        r1.numerator * r2.denominator + r2.numerator * r1.denominator,
        r1.denominator * r2.denominator
    };
    return reduce(result);
}

rational_t subtract(rational_t r1, rational_t r2) {
    rational_t result = {
        r1.numerator * r2.denominator - r2.numerator * r1.denominator,
        r1.denominator * r2.denominator
    };
    return reduce(result);
}

rational_t multiply(rational_t r1, rational_t r2) {
    rational_t result = {
        r1.numerator * r2.numerator,
        r1.denominator * r2.denominator
    };
    return reduce(result);
}

rational_t divide(rational_t r1, rational_t r2) {
    rational_t result = {
        r1.numerator * r2.denominator,
        r1.denominator * r2.numerator
    };
    return reduce(result);
}

rational_t absolute(rational_t r) {
    rational_t result = reduce(r);
    result.numerator = abs(result.numerator);
    result.denominator = abs(result.denominator);
    return result;
}rational_t exp_rational(rational_t r, int16_t n) {
    rational_t result;
    
    if (n == 0) {
        result.numerator = 1;
        result.denominator = 1;
        return result;
    }
    
    // Reducir primero el número racional
    r = reduce(r);
    
    if (n > 0) {
        result.numerator = (int16_t)pow(r.numerator, n);
        result.denominator = (int16_t)pow(r.denominator, n);
    } else {
        // n es negativo
        int16_t abs_n = abs(n);
        
        // Calcular el valor absoluto de la potencia
        int16_t abs_num = (int16_t)pow(abs(r.numerator), abs_n);
        int16_t abs_den = (int16_t)pow(abs(r.denominator), abs_n);
        
        // Ahora determinar el signo
        // Si el número original era negativo y el exponente absoluto es impar, el resultado es negativo
        int sign = 1;
        if (r.numerator < 0 && abs_n % 2 != 0) {
            sign = -1;
        }
        
        // Para exponente negativo, tomamos el recíproco
        result.numerator = sign * abs_den;
        result.denominator = abs_num;
    }
    
    return reduce(result);
}
float exp_real(uint16_t x, rational_t r) {
    rational_t reduced = reduce(r);
    
    if (reduced.numerator == 0) {
        return 1.0f;  // x^0 = 1
    }
    
    // Separar el signo del numerador
    int16_t abs_numerator = abs(reduced.numerator);
    int sign = (reduced.numerator < 0) ? -1 : 1;
    
    // Calcular x^(|numerador|/denominador)
    double base = pow((double)x, 1.0 / reduced.denominator);
    double result = pow(base, abs_numerator);
    
    // Si el numerador era negativo, tomar el recíproco
    if (sign < 0) {
        result = 1.0 / result;
    }
    
    return (float)result;
}