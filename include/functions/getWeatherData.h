#ifndef WEATHER_TRACKER_GETWEATHERDATA_H
#define WEATHER_TRACKER_GETWEATHERDATA_H

#include <string>

bool getWeatherData(const std::string &cityName, const std::string &apiKey, std::string &response);

#endif //WEATHER_TRACKER_GETWEATHERDATA_H
