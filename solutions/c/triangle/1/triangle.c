#include "triangle.h"

// Primero, verificar si es un triangulo valido
bool is_valid_triangle(triangle_t tri) {
    // Todos los lados deben ser positivos
    if (tri.a <= 0 || tri.b <= 0 || tri.c <= 0) {
        return false;
    }
    
    // Desigualdad triangular: la suma de dos lados debe ser mayor que el tercero
    return (tri.a + tri.b > tri.c) && 
           (tri.a + tri.c > tri.b) && 
           (tri.b + tri.c > tri.a);
}

bool is_equilateral(triangle_t tri) {
    if (!is_valid_triangle(tri)) {
        return false;
    }
    return tri.a == tri.b && tri.b == tri.c;
}

bool is_isosceles(triangle_t tri) {
    if (!is_valid_triangle(tri)) {
        return false;
    }
    // Un triangulo isosceles tiene al menos dos lados iguales
    return (tri.a == tri.b) || (tri.b == tri.c) || (tri.a == tri.c);
}

bool is_scalene(triangle_t tri) {
    if (!is_valid_triangle(tri)) {
        return false;
    }
    // Un triangulo escaleno tiene todos los lados diferentes
    return tri.a != tri.b && tri.b != tri.c && tri.a != tri.c;
}


