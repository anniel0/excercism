#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
    // Caso base: el array esta vacio
    if (length == 0) {
        return NULL;
    }
    
    size_t mitad = length / 2;
    
    // Comprobar si encontramos el valor
    if (value == arr[mitad]) {
        return &arr[mitad];  // Devolver puntero al elemento
    }
    
    // Caso base: solo queda un elemento y no es el buscado
    if (length == 1) {
        return NULL;
    }
    
    if (value > arr[mitad]) {
        // Buscar en la mitad derecha (excluyendo el elemento del medio)
        return binary_search(value, arr + mitad + 1, length - mitad - 1);
    } else {
        // Buscar en la mitad izquierda (excluyendo el elemento del medio)
        return binary_search(value, arr, mitad);
    }
}