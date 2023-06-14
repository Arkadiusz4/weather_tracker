#include <iostream>
#include <string>

#include "functions/getWeatherData.h"
#include "apikey.h"
#include "functions/convertKelvinToCelsius.h"
#include "functions/parseWeatherData.h"
#include "functions/printWeatherData.h"

int main() {
    std::string cityName;
    std::string apiKey = getApiKey();

    while (true) {
        std::cout << "Enter the city name (or type 'q' to quit): ";
        std::getline(std::cin, cityName);

        if (cityName == "q") {
            break;
        }

        std::string response;
        if (getWeatherData(cityName, apiKey, response)) {
            double temperature;
            std::string weatherDescription;
            int humidity;

            if (parseWeatherData(response, temperature, weatherDescription, humidity)) {
                double temperatureInCelsius = convertKelvinToCelsius(temperature);
                printWeatherData(cityName, temperatureInCelsius, weatherDescription, humidity);
            }
        }
    }

    return 0;
}
