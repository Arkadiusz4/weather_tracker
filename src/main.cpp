#include <iostream>
#include <string>
#include <curl/curl.h>
#include "../include/apikey.h"

// Callback function for writing HTTP response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int main() {
    std::string cityName;
    std::string apiKey = getApiKey(); // Get the API key from another file (e.g., "apikey.h")

    while (true) {
        std::cout << "Enter the city name (or type 'q' to quit): ";
        std::getline(std::cin, cityName);

        if (cityName == "q") {
            break;
        }

        std::string apiUrl = "https://api.openweathermap.org/data/2.5/weather?q=" + cityName + "&appid=" + apiKey;

        CURL* curl = curl_easy_init();
        if (curl) {
            std::string response;
            curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            CURLcode result = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if (result == CURLE_OK) {
                // The retrieved data is stored in the 'response' variable.
                // You can now parse the response as JSON data and extract the weather information you're interested in.
                // In this example, we're only displaying the temperature and weather description.

                std::cout << "Weather for city " << cityName << ":" << std::endl;

                // Parsing JSON data and extracting temperature, weather description, humidity, etc.
                // In this example, we're skipping this step.

                std::cout << "Temperature: 25.6°C" << std::endl;
                std::cout << "Weather description: Sunny" << std::endl;
                std::cout << "Humidity: 70%" << std::endl;
            }
            else {
                std::cout << "Error while retrieving data: " << curl_easy_strerror(result) << std::endl;
                return 1;
            }
        }
        else {
            std::cout << "Failed to initialize the libcurl library." << std::endl;
            return 1;
        }
    }

    return 0;
}
