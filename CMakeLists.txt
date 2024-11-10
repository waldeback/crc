cmake_minimum_required(VERSION 3.10)


# Set the project name
project(HelloWorld)

# Add an executable
add_executable(hello 
    src/main.c
    src/crc.c
)
target_include_directories(hello PRIVATE ${PROJECT_SOURCE_DIR}/src)

add_executable(crc_test
    test/test_crc_main.c
    src/crc.c
)
target_include_directories(crc_test PRIVATE ${PROJECT_SOURCE_DIR}/src)

add_executable(deserializer_test 
    test/test_deserializer_main.c
    src/command_deserializer.c
)
target_include_directories(deserializer_test PRIVATE ${PROJECT_SOURCE_DIR}/src)

# Enable testing
enable_testing()

# Add a test
add_test(NAME CrcTest COMMAND crc_test)
add_test(NAME DeserializerTest COMMAND deserializer_test)
