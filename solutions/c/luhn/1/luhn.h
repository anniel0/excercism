#ifndef LUHN_H
#define LUHN_H

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int char_to_digit(char c);
bool luhn(const char *num);

#endif
