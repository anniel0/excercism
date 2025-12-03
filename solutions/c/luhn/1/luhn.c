#include "luhn.h"

// Funcion auxiliar para convertir caracter a dígito
int char_to_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return -1;
}

bool luhn(const char *num) {
    int len = strlen(num);
    int sum = 0;
    int digit_count = 0;
    bool double_digit = false; // Empezamos doblando desde el segundo dígito desde la derecha
    
    // Procesar de derecha a izquierda
    for (int i = len - 1; i >= 0; i--) {
        char c = num[i];
        
        // Saltar espacios
        if (c == ' ') {
            continue;
        }
        
        // Verificar que sea un dígito valido
        if (!isdigit((unsigned char)c)) {
            return false;
        }
        
        int digit = c - '0';
        digit_count++;
        
        if (double_digit) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        
        sum += digit;
        double_digit = !double_digit; // Alternar para el siguiente digito
    }
    
    // Necesitamos al menos 2 dígitos (segun especificacion Luhn)
    if (digit_count < 2) {
        return false;
    }
    
    return (sum % 10 == 0);
}