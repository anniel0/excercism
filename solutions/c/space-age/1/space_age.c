#include "space_age.h"


float age(planet_t planet, int64_t seconds) {
    // Constante de segundos en un año terrestre
    const float EARTH_YEAR_SECONDS = 31557600.0;
    
    // Convertir segundos a años terrestres
    float earth_years = seconds / EARTH_YEAR_SECONDS;
    
    switch(planet) {
        case MERCURY: return earth_years / 0.2408467;
        case VENUS:   return earth_years / 0.61519726;
        case EARTH:   return earth_years;
        case MARS:    return earth_years / 1.8808158;
        case JUPITER: return earth_years / 11.862615;
        case SATURN:  return earth_years / 29.447498;
        case URANUS:  return earth_years / 84.016846;
        case NEPTUNE: return earth_years / 164.79132;
        default:      return -1;
    }
}