cmake_minimum_required(VERSION 3.16)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
message(STATUS "${CMAKE_MODULE_PATH}")
SET(CMAKE_COLOR_MAKEFILE ON)

project(FinnCPPDriver)

# specify the C++ standard
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "Using C++ Standard ${CMAKE_CXX_STANDARD}")

#INCLUDES

#XRT
set(XRT_DIR "${CMAKE_SOURCE_DIR}/cmake")
find_package(XRT REQUIRED)

#Boost
find_package(Boost 1.79.0 COMPONENTS system log log_setup program_options filesystem ${BOOST_THREAD} REQUIRED)

add_executable(main main.cpp)
target_compile_options(
main
PRIVATE -Ofast -ffast-math -march=native -mtune=native -fstack-protector-strong -ffunction-sections -fdata-sections -pipe -funroll-loops -fsanitize=address,leak,undefined -static-libasan -g)
target_link_options(main PRIVATE -fsanitize=address,leak,undefined)
target_include_directories(main SYSTEM PRIVATE ${XRT_INCLUDE_DIRS})
target_link_directories(main PRIVATE ${XRT_LIB_CORE_LOCATION} ${XRT_LIB_OCL_LOCATION} ${BOOST_LIBRARYDIR})
target_link_libraries(main PRIVATE xrt_coreutil uuid ${Boost_LIBRARIES})
