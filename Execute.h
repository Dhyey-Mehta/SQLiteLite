#pragma once
#include "Input_buffer.h"
#include "Statement.h"
#include "Table.h"

typedef enum {
  META_COMMAND_SUCCESS,
  META_UNRECOGNIZED_COMMAND
} MetaCommandResult;

MetaCommandResult execute_meta_command(InputBuffer *input_buffer);

typedef enum { 
  EXECUTE_SUCCESS,
  EXECUTE_FAIL
} ExecuteResult;

ExecuteResult execute_insert(Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);
ExecuteResult execute_statement(Statement *statement, Table *table);
