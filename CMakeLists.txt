cmake_minimum_required(VERSION 3.15)

project(web)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Drogon CONFIG REQUIRED)

add_executable(web src/main.cc)

target_link_libraries(web PRIVATE Drogon::Drogon)
