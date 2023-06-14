#include <iostream>
#include "functions/parseWeatherData.h"
#include "json/value.h"
#include "json/reader.h"

bool
parseWeatherData(const std::string &jsonData, double &temperature, std::string &weatherDescription, int &humidity) {

    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(jsonData, root);

    if (parsingSuccessful) {
        temperature = root["main"]["temp"].asDouble();
        weatherDescription = root["weather"][0]["description"].asString();
        humidity = root["main"]["humidity"].asInt();
        return true;
    } else {
        std::cout << "Error while parsing JSON response." << std::endl;
        return false;
    }
}
