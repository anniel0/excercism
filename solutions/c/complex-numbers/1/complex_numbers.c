#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    complex_t r = {(a.real + b.real), (a.imag + b.imag)};
    return r;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t r = {(a.real - b.real), (a.imag - b.imag)};
    return r;
}

complex_t c_mul(complex_t a, complex_t b)
{
    // Formula corregida: (a+bi)(c+di) = (ac - bd) + (ad + bc)i
    complex_t r = {
        (a.real * b.real) - (a.imag * b.imag),
        (a.real * b.imag) + (a.imag * b.real)
    };
    return r;
}

complex_t c_div(complex_t a, complex_t b)
{
    // Fórmula corregida: (a+bi)/(c+di) = ((ac+bd)/(c²+d²)) + ((bc-ad)/(c²+d²))i
    double denominador = (b.real * b.real) + (b.imag * b.imag);
    
    // Evitar division por cero
    if (denominador == 0.0) {
        // Manejo de error: devolver NaN o valor especial
        complex_t r = {NAN, NAN};
        return r;
    }
    
    complex_t r = {
        ((a.real * b.real) + (a.imag * b.imag)) / denominador,
        ((a.imag * b.real) - (a.real * b.imag)) / denominador
    };
    return r;
}

double c_abs(complex_t x)
{
    return sqrt((x.real * x.real) + (x.imag * x.imag));
}

complex_t c_conjugate(complex_t x)
{
    complex_t r = {x.real, -x.imag};
    return r;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    // Fórmula de Euler: e^(a+bi) = e^a * (cos(b) + i*sin(b))
    double exp_real = exp(x.real);
    complex_t r = {
        exp_real * cos(x.imag),
        exp_real * sin(x.imag)
    };
    return r;
}