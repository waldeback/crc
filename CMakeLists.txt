cmake_minimum_required(VERSION 3.10)


# Set the project name
project(HelloWorld)

# Add an executable
add_executable(hello 
    src/main.c
    src/crc.c
)

target_include_directories(hello
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src
)   
