#include <string>
#include <iostream>
#include <iomanip>
#include "functions/printWeatherData.h"

void printWeatherData(const std::string &cityName, double temperatureInCelsius, const std::string &weatherDescription,
                      int humidity) {

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "Weather for city " << cityName << ":" << std::endl;
    std::cout << "Temperature: " << temperatureInCelsius << " C" << std::endl;
    std::cout << "Weather description: " << weatherDescription << std::endl;
    std::cout << "Humidity: " << humidity << "%" << std::endl;
}
