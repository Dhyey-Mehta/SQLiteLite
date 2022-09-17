#include "Execute.h"

MetaCommandResult execute_meta_command(InputBuffer *input_buffer, Table *table) {
  if (strcmp(input_buffer->buffer, ".exit") == 0) {
    free_table(table);
    free_input_buffer(input_buffer);
    exit(EXIT_SUCCESS);
    return META_COMMAND_SUCCESS;
  } else {
    return META_UNRECOGNIZED_COMMAND;
  }
}

ExecuteResult execute_insert(Statement* statement, Table* table){
  // Check for max_rows:
  if (table->num_rows == table->max_rows) {
    return EXECUTE_FAIL;
  }

  Row *new_row = &(statement->row_to_insert);
  compress_row(new_row, row_location(table, table->num_rows));
  table->num_rows += 1;

  return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(Statement* statement, Table* table) {
  Row row;
  for (uint32_t i = 0; i < table->num_rows; i++) {
    decompress_row(row_location(table, i), &row);
    print_row(&row);
  }
  return EXECUTE_SUCCESS;
}

ExecuteResult execute_statement(Statement* statement, Table *table) {
  switch (statement->type) {
    case (STATEMENT_INSERT):
      return execute_insert(statement, table);
    case (STATEMENT_SELECT):
	    return execute_select(statement, table);
  }
}
