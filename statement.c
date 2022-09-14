#include "statement.h"

StatementPrepareStatus prepare_statement(InputBuffer* input_buffer, Statement *statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    statement->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }
  if (strncmp(input_buffer->buffer, "select", 6) == 0) {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }
  
  return PREPARE_UNRECOGNIZED;
}

void execute_statement(Statement *statement) {
  switch(statement->type) {
    case STATEMENT_INSERT:
      printf("Execute insert here\n");
      break;
    case STATEMENT_SELECT:
      printf("Execute select here\n");
      break;
  }
}
