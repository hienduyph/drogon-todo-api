cmake_minimum_required(VERSION 3.15)

project(web)
include_directories("${PROJECT_SOURCE_DIR}/src")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Drogon CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(web
    src/main.cc
    src/index.cc
    src/todo.cc
)

target_link_libraries(web PRIVATE
    Drogon::Drogon
    spdlog::spdlog spdlog::spdlog_header_only
)
