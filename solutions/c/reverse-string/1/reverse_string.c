#include "reverse_string.h"

static void invertir(char* str, int i, int j){
    if (i < j) {
        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        invertir(str, i + 1, j - 1);
    }
}

char *reverse(const char *value) {
    if (value == NULL) {
        return NULL;
    }
    
    size_t len = strlen(value);
    char *str = (char *)malloc(len + 1); // +1 para el caracter nulo
    
    if (str == NULL) {
        return NULL; // Fallo en la asignacion de memoria
    }
    
    strcpy(str, value);
    invertir(str, 0, len - 1);
    return str;
}