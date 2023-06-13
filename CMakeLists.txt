cmake_minimum_required(VERSION 3.25)
project(weather_tracker)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL CONFIG REQUIRED)

include_directories(jsoncpp-master/jsoncpp-master/include)

add_executable(weather_tracker src/main.cpp include/apikey.h jsoncpp-master/jsoncpp-master/src/lib_json/json_reader.cpp jsoncpp-master/jsoncpp-master/src/lib_json/json_value.cpp jsoncpp-master/jsoncpp-master/src/lib_json/json_writer.cpp src/functions/getWeatherData.cpp include/functions/getWeatherData.h src/functions/parseWeatherData.cpp include/functions/parseWeatherData.h src/functions/convertKelvinToCelsius.cpp include/functions/convertKelvinToCelsius.h src/functions/printWeatherData.cpp include/functions/printWeatherData.h)

target_link_libraries(weather_tracker PRIVATE CURL::libcurl)
target_link_libraries(weather_tracker PRIVATE ${CMAKE_SOURCE_DIR}/jsoncpp-master/jsoncpp-master/build/lib/Release/jsoncpp.lib)
