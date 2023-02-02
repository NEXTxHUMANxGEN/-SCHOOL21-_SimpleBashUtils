void cat_read_func(int argc, char *const argv[], unsigned const flags[]) {
  FILE *file;
  int str_counter = 0;
  for (int argv_count = 1; argv_count < argc; argv_count++) {
    if (argv[argv_count][0] != '-') {
      file = fopen(argv[argv_count], "r");
      if (file != NULL) {
        char c = ' ';
        // int str_counter = 0;
        int first_empty_str_flag = 1;
        char prev_char = ' ';
        if (flags[0] > 0) {
          printf("%6u", ++str_counter);
          printf("%c", 9);
        } else if (flags[2] > 0) {
          printf("%6u", ++str_counter);
          printf("%c", 9);
        }
        while ((c = fgetc(file)) != EOF) {
          if (flags[4] > 0 && first_empty_str_flag > 0 && c == '\n') {
            continue;
          }
          if (flags[4] > 0 && prev_char == '\n' && c == '\n') {
            first_empty_str_flag = 1;
          } else {
            first_empty_str_flag = 0;
          }
          if (flags[0] > 0 && prev_char == '\n' && c != '\n') {
            printf("%6u", ++str_counter);
            printf("%c", 9);
          } else if (flags[2] > 0 && flags[0] < 1 && prev_char == '\n') {
            printf("%6u", ++str_counter);
            printf("%c", 9);
          }
          if (flags[3] > 0 && c == 9) {
            prev_char = c;
            printf("^I");
            continue;
          }

          if (flags[1] > 0 && c == '\n') {
            printf("$");
          }
          printf("%c", c);
          prev_char = c;
        }
        // str_counter = 0;
      } else {
        printf("No such file or derictory\n");
        // puts(argv[argv_count]);
      }
    }
  }
}