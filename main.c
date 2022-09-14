#include <stdio.h>
#include "input_buffer.h"
#include "meta_command.h"
#include "statement.h"


int main() {
    InputBuffer *input_buffer = create_input_buffer();
    while (1) {
       printf("db > ");
       read_input(input_buffer);
       if (input_buffer->buffer[0] == '.') {
         switch (execute_meta_command(input_buffer)) {
          case META_COMMAND_SUCCESS:
            continue;
          case META_UNRECOGNIZED_COMMAND:
            printf("Unrecognized command!\n");
            continue;
         }
       }

      Statement statement;
      switch(prepare_statement(input_buffer, &statement)) {
        case PREPARE_SUCCESS:
          break;
        case PREPARE_UNRECOGNIZED:
          printf("Unrecognized command!\n");
          continue;
      }
      execute_statement(&statement);
      printf("Executed statement!\n");
    }
}
