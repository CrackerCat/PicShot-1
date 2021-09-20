cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME PicShot)
#set(PROJECT_VERSION_MAJOR 0)
#set(PROJECT_VERSION_MINOR 1)

project(${PROJECT_NAME})

add_subdirectory(XCore)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(WINDOW_FILES
        main.cpp)

add_executable(PicShot XCore ${WINDOW_FILES})
target_link_libraries(PicShot
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )