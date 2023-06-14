#include "functions/getWeatherData.h"
#include <curl/curl.h>
#include <string>
#include <iostream>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char *>(contents), totalSize);
    return totalSize;
}

bool getWeatherData(const std::string &cityName, const std::string &apiKey, std::string &response) {
    const std::string apiUrl = "https://api.openweathermap.org/data/2.5/weather?q=" + cityName + "&appid=" + apiKey;

    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode result = curl_easy_perform(curl);
        long httpCode;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
        curl_easy_cleanup(curl);

        if (result == CURLE_OK) {
            if (httpCode == 200) {
                return true;
            } else if (httpCode == 404) {
                std::cout << "City not found: " << cityName << std::endl;
            } else {
                std::cout << "Error while retrieving data. HTTP status code: " << httpCode << std::endl;
            }
        } else {
            std::cout << "Error while retrieving data: " << curl_easy_strerror(result) << std::endl;
        }
    } else {
        std::cout << "Failed to initialize the libcurl library." << std::endl;
    }

    return false;
}
