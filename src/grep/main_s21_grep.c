#include <stdio.h>
#include <stdlib.h>

#include "s21_grep.h"

int main(int argc, char* const argv[]) {
  unsigned i_flag = 0;
  unsigned v_flag = 0;
  unsigned c_flag = 0;
  unsigned l_flag = 0;
  unsigned n_flag = 0;
  unsigned h_flag = 0;
  unsigned s_flag = 0;
  unsigned ef_flag = 0;
  unsigned o_flag = 0;
  unsigned flags[] = {i_flag, v_flag, c_flag,  l_flag, n_flag,
                      h_flag, s_flag, ef_flag, o_flag};
  int count = 1;
  unsigned inner_count = 1;
  while (count < argc) {
    if (argv[count][0] == '-') {
      while (argv[count][inner_count] != '\0') {
        switch (argv[count][inner_count]) {
          case 'i':
            flags[0] = 1;
            break;
          case 'v':
            flags[1] = 1;
            break;
          case 'c':
            flags[2] = 1;
            break;
          case 'l':
            flags[3] = 1;
            break;
          case 'n':
            flags[4] = 1;
            break;
          case 'h':
            flags[5] = 1;
            break;
          case 's':
            flags[6] = 1;
            break;
          case 'e':
            flags[7] = 1;
            break;
          case 'f':
            flags[7] = 1;
            break;
          case 'o':
            flags[8] = 1;
            break;
          default:
            break;
        }
        inner_count++;
      }
    }
    count++;
    inner_count = 1;
  }
  unsigned file_name_count = 0;

  if (flags[7] > 0) {
    for (int argv_count = 1; argv_count < argc; argv_count++) {
      if (argv[argv_count][0] == '-' &&
          (argv[argv_count][1] == 'f' || argv[argv_count][1] == 'e')) {
        argv_count++;
        continue;
      } else if (argv[argv_count][0] == '-') {
        continue;
      } else {
        file_name_count++;
      }
    }
    if (file_name_count < 2) {
      flags[5] = 1;
    }
    grep_read_func_ef(argc, argv, flags);
  } else if (flags[7] < 1) {
    for (int argv_count = 1; argv_count < argc; argv_count++) {
      if (argv[argv_count][0] == '-' &&
          (argv[argv_count][1] == 'f' || argv[argv_count][1] == 'e')) {
        argv_count++;
        continue;
      } else if (argv[argv_count][0] == '-') {
        continue;
      } else {
        file_name_count++;
      }
    }
    if (file_name_count < 3) {
      flags[5] = 1;
    }
    grep_read_func_noef(argc, argv, flags);
  } else {
    printf("Unexpected error EF flags\n");
  }
  return 0;
}