# WeatherTracker

This is a simple weather application written in C++. It retrieves current weather data using the OpenWeatherMap API and
displays information such as temperature, weather description, and humidity for a given city.

----

## Table of Contents

1. [How it works](#how-it-works)
2. [Example Input/Output](#example-inputoutput)
3. [Libraries Used](#libraries-used)
4. [Getting Started](#getting-started)
5. [Creating Your API Key](#creating-your-api-key)
6. [License](#license)

---
<a name="how-it-works"></a>

## How It Works

1. The application prompts the user to enter the name of a city for which they want to retrieve weather data.
2. It sends an HTTP request to the OpenWeatherMap API with the provided city name and the API key.
3. The API responds with weather data in JSON format.
4. The application parses the JSON response to extract the relevant weather information.
5. The extracted weather information (e.g., temperature, weather description, humidity) is displayed to the user.

----
<a name="example-inputoutput"></a>

## Example Input/Output

**Input**

```
Enter the city name (or type 'q' to quit): London
```

**Output**

```
Weather for city London:
Temperature: 25.6°C
Weather description: Sunny
Humidity: 70%
```

----
<a name="libraries-used"></a>

## Libraries Used

- **[libcurl](https://curl.se/)**: A library for making HTTP requests and retrieving data from APIs.
- **[JsonCpp](https://github.com/open-source-parsers/jsoncpp)**: JsonCpp is a C++ library that allows manipulating JSON values, including serialization and deserialization to and from strings.

Make sure to have these libraries installed on your system before compiling the application.

----
<a name="getting-started"></a>

## Getting Started

To get started with this project, follow these steps:

1. Clone this repository using the following command:

   ```
   git clone https://github.com/Arkadiusz4/weather_tracker.git
   ```

2. Install the necessary dependencies, including the `libcurl` and `JsonCpp` libraries.

3. Create your own OpenWeatherMap API key by signing up for a free account on
   the [OpenWeatherMap](https://openweathermap.org/) website. Copy the generated API key.

4. Open the `apikey.h` file in the project and replace the existing placeholder API key with your own key. Save the
   file.

5. Compile the code using a C++ compiler with the necessary libraries linked.

6. Run the compiled executable.

7. Enter the name of the city for which you want to retrieve weather data.

8. The application will display the current weather information for the provided city.

----
<a name="creating-your-api-key"></a>

## Creating Your API Key

To create your own API key for OpenWeatherMap, follow these steps:

1. Visit the [OpenWeatherMap website](https://openweathermap.org/) and sign up for a free account.
2. After signing in, go to your account dashboard and navigate to the API Keys section.
3. Generate a new API key or use an existing one.
4. Copy the generated API key.
5. Open the `apikey.h` file in the project and replace the existing placeholder API key with your own key.
6. Save the file.

Make sure to keep your API key secure and do not share it publicly.

### API key file

Create a file called `apikey.h` in the project directory Place it in the `include` folder.

Open the `apikey.h` file and paste the following code:

```cpp
#ifndef WEATHER_TRACKER_APIKEY_H
#define WEATHER_TRACKER_APIKEY_H

#include <string>

std::string getApiKey() {
    return "YOUR_API_KEY";
}

#endif //WEATHER_TRACKER_APIKEY_H
```

Replace "YOUR_API_KEY" with your actual API key. Save the file.

----
<a name="license"></a>

## License

This project is licensed under the [MIT License](LICENSE).
