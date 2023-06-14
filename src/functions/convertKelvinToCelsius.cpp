#include "functions/convertKelvinToCelsius.h"

double convertKelvinToCelsius(double temperatureInKelvin) {
    constexpr double DIFFERENCE_KELVIN_CELSIUS = 273.15;

    return temperatureInKelvin - DIFFERENCE_KELVIN_CELSIUS;
}
