#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define TABLE_MAX_PAGES 100
#define PAGE_SIZE 4096

typedef struct {
  int file_desc;
  uint32_t file_len;
  void *pages[TABLE_MAX_PAGES];
} Pager;

Pager *pager_start(const char *filename);
void* get_page(Pager* pager, uint32_t page_num);
void pager_flush(Pager* pager, uint32_t page_num, uint32_t size);
