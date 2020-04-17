# CMakeLists.txt
# Mark Guerra
# 11/1/2015

cmake_minimum_required(VERSION 2.8)
project(BigNumber)

set(BigNumber_VERSION_MAJOR 1)
set(BigNumber_VERSION_MINOR 0)

if (WIN32)
    set(c++version -std=gnu++14)
else()
    set(c++version -std=c++14)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++ -pedantic -Wno-unused-function ${c++version}")

set(CMAKE_BUILD_TYPE Release)

set(SOURCE_FILES
        src/bignumber.cpp  main.cpp )

add_library(BigNumber ${SOURCE_FILES})

set(CMAKE_BUILD_TYPE Debug)

if(WIN32)
    install(TARGETS BigNumber DESTINATION C:/Libs/BigNumber/lib)
    install(FILES src/bignumber.h DESTINATION C:/Libs/BigNumber/include)
else()
    install(TARGETS BigNumber DESTINATION ~/Library/Frameworks/BigNumber/lib)
    install(FILES src/bignumber.h DESTINATION ~/Library/Frameworks/BigNumber/include)
endif()
install(TARGETS BigNumber DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin/BigNumber/lib)
install(FILES src/bignumber.h DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin/BigNumber/include)

add_custom_command(
        TARGET BigNumber
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target install
)

add_executable(BigNumberRun ${SOURCE_FILES})
