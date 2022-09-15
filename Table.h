#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

typedef struct {
  uint32_t id;
  // +1 for null char
  char username[COLUMN_USERNAME_SIZE + 1];
  char email[COLUMN_EMAIL_SIZE + 1];
} Row;

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute);
#define TABLE_MAX_PAGES 100

typedef struct {
  uint32_t num_rows;
  void* pages[TABLE_MAX_PAGES];
  uint32_t max_rows;
} Table;

Table* new_table();
void free_table(Table* table);

void* row_location(Table* table, uint32_t row_num);
void compress_row(Row *source, void *destination);
void decompress_row(void *source, Row *destination);
void print_row(Row *row);
