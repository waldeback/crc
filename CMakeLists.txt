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

add_executable(hello_test 
    test/main.c
    src/crc.c
)

target_include_directories(hello_test
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src
)

# Enable testing
enable_testing()

# Add a test
add_test(NAME HelloWorldTest COMMAND hello_test)
