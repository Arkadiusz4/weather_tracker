#ifndef WEATHER_TRACKER_PARSEWEATHERDATA_H
#define WEATHER_TRACKER_PARSEWEATHERDATA_H

#include <string>

bool parseWeatherData(const std::string &jsonData, double &temperature, std::string &weatherDescription, int &humidity);

#endif //WEATHER_TRACKER_PARSEWEATHERDATA_H
