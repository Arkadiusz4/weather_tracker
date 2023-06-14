#include <string>
#include <iostream>
#include <iomanip>
#include "functions/printWeatherData.h"

std::string capitalizeFirstLetter(const std::string &str) {
    std::string result = str;
    if (!result.empty()) {
        result[0] = std::toupper(result[0]);
    }

    return result;
}

void printWeatherData(const std::string &cityName, double temperatureInCelsius, const std::string &weatherDescription,
                      int humidity) {

    std::cout << std::fixed << std::setprecision(1);
    std::string capitalizedCityName = capitalizeFirstLetter(cityName);


    std::cout << "Weather for city " << capitalizedCityName << ":" << std::endl;
    std::cout << "Temperature: " << temperatureInCelsius << " C" << std::endl;
    std::cout << "Weather description: " << weatherDescription << std::endl;
    std::cout << "Humidity: " << humidity << "%" << std::endl;
}
