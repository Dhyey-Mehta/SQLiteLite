#include "meta_command.h"

MetaCommandResult execute_meta_command(InputBuffer *input_buffer) {
  if (strcmp(input_buffer->buffer, ".exit") == 0) {
    free_input_buffer(input_buffer);
    exit(EXIT_SUCCESS);
    return META_COMMAND_SUCCESS;
  } else {
    return META_UNRECOGNIZED_COMMAND;
  }
}
