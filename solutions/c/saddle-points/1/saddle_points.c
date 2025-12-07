#include "saddle_points.h"


saddle_points_t *saddle_points(size_t rows, size_t columns, uint8_t matrix[][columns]) {
    // Crear estructura de resultado
    saddle_points_t *result = malloc(sizeof(saddle_points_t));
    if (!result) return NULL;
    
    result->count = 0;
    result->points = NULL;
    
    // Caso matriz vacia
    if (rows == 0 || columns == 0) {
        return result;
    }
    
    // Para cada elemento de la matriz
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            uint8_t current = matrix[i][j];
            bool is_saddle = true;
            
            // Verificar si es el maximo en su fila
            for (size_t col = 0; col < columns; col++) {
                if (matrix[i][col] > current) {
                    is_saddle = false;
                    break;
                }
            }
            
            // Si no es maximo en su fila, continuar
            if (!is_saddle) continue;
            
            // Verificar si es el minimo en su columna
            for (size_t row = 0; row < rows; row++) {
                if (matrix[row][j] < current) {
                    is_saddle = false;
                    break;
                }
            }
            
            // Si es punto de silla, agregarlo a la lista
            if (is_saddle) {
                result->count++;
                result->points = realloc(result->points, result->count * sizeof(saddle_point_t));
                if (!result->points) {
                    free(result);
                    return NULL;
                }
                result->points[result->count - 1].row = i + 1;    // 1-indexed
                result->points[result->count - 1].column = j + 1; // 1-indexed
            }
        }
    }
    
    return result;
}

void free_saddle_points(saddle_points_t *saddle_points) {
    if (saddle_points) {
        free(saddle_points->points);
        free(saddle_points);
    }
}