#pragma once
#include <stdio.h>
#include "input_buffer.h"

typedef enum { 
STATEMENT_INSERT, 
STATEMENT_SELECT 
} StatementType;

typedef struct {
  StatementType type;
} Statement;

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED
} StatementPrepareStatus;

StatementPrepareStatus prepare_statement(InputBuffer* input_buffer, Statement *statement);

void execute_statement(Statement *statement);
