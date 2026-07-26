cmake_minimum_required(VERSION 3.20)

project(DevQuest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DevQuest
    src/main.cpp
    src/App.cpp
    src/CommandHandler.cpp
)

target_include_directories(DevQuest PRIVATE include)