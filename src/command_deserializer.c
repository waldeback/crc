#include <command_deserializer.h>

#include <stdint.h>
#include <string.h>


#define DESERIALIZER_BUFFER_SIZE 100
static uint8_t deserializer_buffer[DESERIALIZER_BUFFER_SIZE];
static size_t deserializer_buffer_index = 0;

static size_t append_to_deserializer_buffer(const void *buffer, size_t size)
{
    const size_t available_bytes = DESERIALIZER_BUFFER_SIZE - deserializer_buffer_index;
    const size_t bytes_to_copy = (size < available_bytes) ? size : available_bytes;

    memcpy(&deserializer_buffer[deserializer_buffer_index], buffer, size);
    deserializer_buffer_index += size;

    return bytes_to_copy;
}


void deserialize_command(const void *buffer, size_t size)
{
    while(size > 0)
    {
        const size_t bytes_copied = append_to_deserializer_buffer(buffer, size);

        buffer = &((const char*)buffer)[bytes_copied];
        size -= bytes_copied;
    } 
}