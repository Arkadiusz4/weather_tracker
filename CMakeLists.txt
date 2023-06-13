cmake_minimum_required(VERSION 3.25)
project(weather_tracker)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL CONFIG REQUIRED)

include_directories(jsoncpp-master/jsoncpp-master/include)

add_executable(weather_tracker src/main.cpp include/apikey.h jsoncpp-master/jsoncpp-master/src/lib_json/json_reader.cpp jsoncpp-master/jsoncpp-master/src/lib_json/json_value.cpp jsoncpp-master/jsoncpp-master/src/lib_json/json_writer.cpp src/getWeatherData.cpp include/getWeatherData.h src/parseWeatherData.cpp include/parseWeatherData.h src/convertKelvinToCelsius.cpp include/convertKelvinToCelsius.h src/printWeatherData.cpp include/printWeatherData.h)

target_link_libraries(weather_tracker PRIVATE CURL::libcurl)
target_link_libraries(weather_tracker PRIVATE ${CMAKE_SOURCE_DIR}/jsoncpp-master/jsoncpp-master/build/lib/Release/jsoncpp.lib)
