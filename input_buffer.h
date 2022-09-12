#include <stdio.h>

typedef struct {
    char *buffer;
    size_t buffer_len;
    ssize_t input_len;
} InputBuffer;

InputBuffer* create_input_buffer();

void free_input_buffer();

void read_input(InputBuffer* input_buffer);
