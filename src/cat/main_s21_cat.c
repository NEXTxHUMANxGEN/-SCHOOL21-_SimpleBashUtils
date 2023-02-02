#include <stdio.h>
#include <stdlib.h>

#include "s21_cat.h"

int main(int argc, char* argv[]) {
  unsigned int b_flag = 0;
  unsigned int e_flag = 0;
  unsigned int n_flag = 0;
  unsigned int t_flag = 0;
  unsigned int s_flag = 0;
  unsigned inner_count = 1;
  int count = 0;
  while (count < argc) {
    if (argv[count][0] == '-') {
      while (argv[count][inner_count] != '\0') {
        switch (argv[count][inner_count]) {
          case 'b':
            b_flag = 1;
            break;
          case 'e':
            e_flag = 1;
            break;
          case 'n':
            n_flag = 1;
            break;
          case 't':
            t_flag = 1;
            break;
          case 's':
            s_flag = 1;
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
  unsigned flags[] = {b_flag, e_flag, n_flag, t_flag, s_flag};
  cat_read_func(argc, argv, flags);
  return 0;
}