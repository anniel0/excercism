#include "two_fer.h"

void two_fer(char *buffer, const char *name) {
 const char *default_name = "you";
    
    if (name == NULL || name[0] == '\0') {
        name = default_name;
    }
    
    snprintf(buffer, 100, "One for %s, one for me.", name);
}