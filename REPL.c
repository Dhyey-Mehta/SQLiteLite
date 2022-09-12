#include "input_buffer.h"
#include <stdio.h>
#include <string.h>


int main() {
    InputBuffer *input_buffer = create_input_buffer();
    while (1) {
       printf("db > ");
       read_input(input_buffer);
       if (strcmp(input_buffer -> buffer, "exit") == 0) {
        free_input_buffer(input_buffer);
        return 0;
       } else {
        printf("Unrecognized command!");
       }
    }
}