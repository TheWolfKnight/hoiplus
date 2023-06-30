
#include <string>
#include <cstdlib>
#include <cstdio>

#ifndef _GLOBALS_DEFINITION
#define _GLOBALS_DEFINITION

bool MAY_COMPILE = true;

void write_warrning(const char* msg, const char* file_path, size_t row, size_t col)
{
  printf("%s:%lli:%lli WARRNING: %s\n", file_path, row, col, msg);
}

void write_error(const char* msg, const char* file_path, size_t row, size_t col)
{
  printf("%s:%lli:%lli ERROR: %s\n", file_path, row, col, msg);
  MAY_COMPILE = false;
}

#endif // _GLOBALS_DEFINITION
