#ifndef COMMAND_DESERIALIZER_H
#define COMMAND_DESERIALIZER_H

#include <stddef.h>

void deserialize_command(const void *buffer, size_t size);

#endif /* COMMAND_DESERIALIZER_H */