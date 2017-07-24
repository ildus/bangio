cmake_minimum_required(VERSION 3.4.0)

project(bangio)

# Find source files
file(GLOB SOURCES src/*.c)

# Include header files
include_directories(include)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

# Install library headers
file(GLOB HEADERS include/lib${PROJECT_NAME}.h)
install(FILES ${HEADERS} DESTINATION include)

add_executable(test_spi test.c)
target_link_libraries(test_spi -lbangio)

