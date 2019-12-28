cmake_minimum_required(VERSION 3.15)
project(RextesterPP)


find_package(nlohmann_json REQUIRED)


set(CMAKE_CXX_STANDARD 14)



add_executable(${PROJECT_NAME} main.cpp src/rextester.cpp)


target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json curl)


target_include_directories(${PROJECT_NAME} PRIVATE include)