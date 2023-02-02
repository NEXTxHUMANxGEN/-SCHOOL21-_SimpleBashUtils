#ifndef regex
#define regex
#include <regex.h>
#include <string.h>
#endif

void grep_read_func_ef(int const argc, char *const argv[],
                       unsigned const flags[]);
void grep_read_func_noef(int const argc, char *const argv[],
                         unsigned const flags[]);
#include "s21_grep.c"