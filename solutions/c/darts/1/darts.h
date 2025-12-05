#ifndef DARTS_H
#define DARTS_H

#include <math.h>

typedef struct {
    double x,y;
} coordinate_t;

double punto( coordinate_t p);
int score(coordinate_t x);

#endif
