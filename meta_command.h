#pragma once
#include <stdio.h>
#include <string.h>
#include "input_buffer.h"

typedef enum {
  META_COMMAND_SUCCESS,
  META_UNRECOGNIZED_COMMAND
} MetaCommandResult;

MetaCommandResult execute_meta_command(InputBuffer *input_buffer);
