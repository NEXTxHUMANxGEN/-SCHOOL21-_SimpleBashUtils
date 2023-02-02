void grep_read_func_ef(int const argc, char *const argv[],
                       unsigned const flags[]) {
  int tmp_len = 1;
  char *reg_expresion = (char *)malloc(tmp_len * sizeof(char));
  reg_expresion[0] = '(';
  regex_t regex_exp;
  int regexec_res = 0;
  regmatch_t pmatch[1];
  const size_t nmatch = 1;

  FILE *file;
  FILE *regex_file;

  for (int argv_count = 1; argv_count < argc; argv_count++) {
    if (argv[argv_count][0] == '-' && argv[argv_count][1] == 'f') {
      if (++argv_count < argc) {
        regex_file = fopen(argv[argv_count], "r");
        if (regex_file != NULL) {
          char c = ' ';
          while ((c = fgetc(regex_file)) != EOF) {
            if (c != '\n') {
              reg_expresion =
                  (char *)realloc(reg_expresion, (tmp_len + 1) * sizeof(char));
              reg_expresion[tmp_len] = c;
              if (flags[0] > 0 && (c > 64 && c < 91)) {
                reg_expresion[tmp_len] += 32;
              }
              tmp_len++;
              continue;
            }
            if (reg_expresion[tmp_len - 1] != '|') {
              reg_expresion =
                  (char *)realloc(reg_expresion, (tmp_len + 1) * sizeof(char));
              reg_expresion[tmp_len] = '|';
              tmp_len++;
            }
          }
          fclose(regex_file);
        } else {
          puts("regex file name error");
          // fprintf(stderr, "error")
        }
      }
    } else if (argv[argv_count][0] == '-' && argv[argv_count][1] == 'e') {
      if (++argv_count < argc) {
        for (unsigned long opt_len_count = 0;
             opt_len_count < strlen(argv[argv_count]); opt_len_count++) {
          reg_expresion =
              (char *)realloc(reg_expresion, (tmp_len + 1) * sizeof(char));
          reg_expresion[tmp_len] = argv[argv_count][opt_len_count];
          if (flags[0] > 0) {
            if ((reg_expresion[tmp_len] > 64 && reg_expresion[tmp_len] < 91)) {
              reg_expresion[tmp_len] += 32;
            }
          }
          tmp_len++;
        }
        reg_expresion =
            (char *)realloc(reg_expresion, (tmp_len + 1) * sizeof(char));
        reg_expresion[tmp_len] = '|';
        tmp_len++;
      }
    }
  }
  reg_expresion = (char *)realloc(reg_expresion, (tmp_len + 1) * sizeof(char));
  reg_expresion[tmp_len - 1] = ')';
  reg_expresion[tmp_len] = '\0';
  int exit_flag = 0;
  regexec_res = regcomp(&regex_exp, reg_expresion, REG_EXTENDED);
  if (regexec_res != 0) {
    printf("Could not compile regex\n");
    printf("%s", reg_expresion);
    printf("\n");
    exit_flag = 1;
  }
  free(reg_expresion);

  if (exit_flag == 0) {
    for (int argv_count = 1; argv_count < argc; argv_count++) {
      if (argv[argv_count][0] == '-' &&
          (argv[argv_count][1] == 'f' || argv[argv_count][1] == 'e')) {
        argv_count++;
        continue;
      } else if (argv[argv_count][0] == '-') {
        continue;
      } else {
        // if (argv[argv_count][0] != '-'){
        file = fopen(argv[argv_count], "r");
        if (file != NULL) {
          char c = ' ';
          int regexed_str = 0;
          int in_file_str = 0;
          int regexed_succes = 0;
          char *scaned_string_arr = (char *)malloc(0 * sizeof(char));
          int scaned_string_len = 0;
          while ((c = fgetc(file)) != EOF) {
            if (flags[0] > 0 && (c > 64 && c < 91)) {
              c += 32;
            }
            if (c != '\n') {
              scaned_string_arr = (char *)realloc(
                  scaned_string_arr, (scaned_string_len + 1) * sizeof(char));
              scaned_string_arr[scaned_string_len] = c;
              scaned_string_len++;
              continue;
            }
            if (c == '\n') {
              in_file_str++;
              regexec_res = 1;
              scaned_string_arr = (char *)realloc(
                  scaned_string_arr, (scaned_string_len + 1) * sizeof(char));
              scaned_string_arr[scaned_string_len] = '\0';
              regexec_res =
                  regexec(&regex_exp, scaned_string_arr, nmatch, pmatch, 0);
              if (regexec_res == 0 && flags[1] < 1) {
                regexed_str++;
                if (flags[3] > 0) {
                  regexed_succes = 1;
                  break;
                }
                if (flags[5] < 1 && flags[2] < 1 && flags[3] < 1) {
                  printf("%s:", argv[argv_count]);
                }
                if (flags[4] > 0 && flags[2] < 1 && flags[3] < 1) {
                  printf("%d:", in_file_str);
                }
                if (flags[2] < 1 && flags[3] < 1 && flags[8] < 1) {
                  printf("%s", scaned_string_arr);
                  printf("%c", c);
                } else if (flags[2] < 1 && flags[3] < 1 && flags[8] > 0) {
                  for (int count = pmatch[0].rm_so; count < pmatch[0].rm_eo;
                       count++) {
                    printf("%c", scaned_string_arr[count]);
                  }
                  printf("%c", c);
                }
              } else if (regexec_res != 0 && flags[1] > 0) {
                regexed_str++;
                if (flags[3] > 0) {
                  regexed_succes = 1;
                  break;
                }
                if (flags[5] < 1 && flags[2] < 1 && flags[3] < 1) {
                  printf("%s:", argv[argv_count]);
                }
                if (flags[4] > 0 && flags[2] < 1 && flags[3] < 1) {
                  printf("%d:", in_file_str);
                }
                if (flags[2] < 1 && flags[3] < 1 && flags[8] < 1) {
                  printf("%s", scaned_string_arr);
                  printf("%c", c);
                } else if (flags[2] < 1 && flags[3] < 1 && flags[8] > 0) {
                  for (int count = pmatch[0].rm_so; count < pmatch[0].rm_eo;
                       count++) {
                    printf("%c", scaned_string_arr[count]);
                  }
                  printf("%c", c);
                }
              }
              scaned_string_len = 0;
              scaned_string_arr =
                  (char *)realloc(scaned_string_arr, 1 * sizeof(char));
              scaned_string_arr[0] = '\0';
            }
          }
          // /*
          in_file_str++;
          regexec_res = 1;
          scaned_string_arr = (char *)realloc(
              scaned_string_arr, (scaned_string_len + 1) * sizeof(char));
          scaned_string_arr[scaned_string_len] = '\0';
          regexec_res =
              regexec(&regex_exp, scaned_string_arr, nmatch, pmatch, 0);
          if (regexec_res == 0 && flags[1] < 1) {
            regexed_str++;
            if (flags[3] > 0) {
              regexed_succes = 1;
            }
            if (flags[5] < 1 && flags[2] < 1 && flags[3] < 1) {
              printf("%s:", argv[argv_count]);
            }
            if (flags[4] > 0 && flags[2] < 1 && flags[3] < 1) {
              printf("%d:", in_file_str);
            }
            if (flags[2] < 1 && flags[3] < 1 && flags[8] < 1) {
              printf("%s", scaned_string_arr);
              printf("\n");
            } else if (flags[2] < 1 && flags[3] < 1 && flags[8] > 0) {
              for (int count = pmatch[0].rm_so; count < pmatch[0].rm_eo;
                   count++) {
                printf("%c", scaned_string_arr[count]);
              }
              printf("\n");
            }
          } else if (regexec_res != 0 && flags[1] > 0) {
            regexed_str++;
            if (flags[3] > 0) {
              regexed_succes = 1;
            }
            if (flags[5] < 1 && flags[2] < 1 && flags[3] < 1) {
              printf("%s:", argv[argv_count]);
            }
            if (flags[4] > 0 && flags[2] < 1 && flags[3] < 1) {
              printf("%d:", in_file_str);
            }
            if (flags[2] < 1 && flags[3] < 1 && flags[8] < 1) {
              printf("%s", scaned_string_arr);
              printf("\n");
            } else if (flags[2] < 1 && flags[3] < 1 && flags[8] > 0) {
              for (int count = pmatch[0].rm_so; count < pmatch[0].rm_eo;
                   count++) {
                printf("%c", scaned_string_arr[count]);
              }
              printf("\n");
            }
          }
          // */

          if (flags[2] > 0 && flags[3] < 1) {
            if (flags[5] < 1) {
              printf("%s:", argv[argv_count]);
            }
            printf("%d\n", regexed_str);
          }
          if (regexed_succes > 0 && flags[3] > 0) {
            printf("%s\n", argv[argv_count]);
          }
          free(scaned_string_arr);
          in_file_str = 0;
          fclose(file);
        } else {
          if (flags[6] < 1) {
            printf("%s: ", argv[argv_count]);
            puts("No such file or derictory");
          }
        }
      }
    }
    regfree(&regex_exp);
  }
}

void grep_read_func_noef(int const argc, char *const argv[],
                         unsigned const flags[]) {
  int tmp_len = 0;
  char *reg_expresion = (char *)malloc(tmp_len + 1 * sizeof(char));
  regex_t regex_exp;
  int regexec_res = 0;
  regmatch_t pmatch[1];
  const size_t nmatch = 1;

  FILE *file;
  unsigned reg_size = 0;
  int argv_count = 1;
  while (argv_count < argc) {
    if (argv[argv_count][0] != '-') {
      reg_expresion = (char *)realloc(
          reg_expresion, (strlen(argv[argv_count])) * sizeof(char));
      for (unsigned long count = 0; count < strlen(argv[argv_count]); count++) {
        reg_expresion[count] = argv[argv_count][count];
        if (flags[0] > 0) {
          if ((reg_expresion[count] > 64 && reg_expresion[count] < 91)) {
            reg_expresion[count] += 32;
          }
        }
        reg_size++;
      }
      argv_count++;
      break;
    }
    argv_count++;
  }
  reg_expresion = (char *)realloc(reg_expresion, (reg_size + 1) * sizeof(char));
  reg_expresion[reg_size] = '\0';
  int exit_flag = 0;
  regexec_res = regcomp(&regex_exp, reg_expresion, 0);
  if (regexec_res != 0) {
    printf("Could not compile regex\n");
    printf("%s", reg_expresion);
    printf("\n");
    exit_flag = 1;
  }
  free(reg_expresion);
  regexec_res = 1;
  if (exit_flag == 0) {
    while (argv_count < argc) {
      if (argv[argv_count][0] != '-') {
        file = fopen(argv[argv_count], "r");
        if (file != NULL) {
          char c = ' ';
          int regexed_str = 0;
          int in_file_str = 0;
          int regexed_succes = 0;
          char *scaned_string_arr = (char *)malloc(0 * sizeof(char));
          int scaned_string_len = 0;
          while ((c = fgetc(file)) != EOF) {
            if (flags[0] > 0 && (c > 64 && c < 91)) {
              c += 32;
            }
            if (c != '\n') {
              scaned_string_arr =
                  (char *)realloc(scaned_string_arr,
                                  (scaned_string_len + 1) + 1 * sizeof(char));
              scaned_string_arr[scaned_string_len] = c;
              scaned_string_len++;
              continue;
            }
            if (c == '\n') {
              in_file_str++;
              regexec_res = 1;
              scaned_string_arr[scaned_string_len] = '\0';
              regexec_res =
                  regexec(&regex_exp, scaned_string_arr, nmatch, pmatch, 0);
              if (regexec_res == 0 && flags[1] < 1) {
                regexed_str++;
                if (flags[3] > 0) { /*l_flag > 0*/
                  regexed_succes = 1;
                  break;
                }
                if (flags[5] < 1 && flags[2] < 1 &&
                    flags[3] < 1) { /*h_flag <1 && c_flag < 1 && l_flag < 1 */
                  printf("%s:", argv[argv_count]);
                }
                if (flags[4] > 0 && flags[2] < 1 && flags[3] < 1) {
                  printf("%d:", in_file_str);
                }
                if (flags[2] < 1 && flags[3] < 1 && flags[8] < 1) {
                  printf("%s", scaned_string_arr);
                  printf("%c", c);
                } else if (flags[2] < 1 && flags[3] < 1 && flags[8] > 0) {
                  for (int count = pmatch[0].rm_so; count < pmatch[0].rm_eo;
                       count++) {
                    printf("%c", scaned_string_arr[count]);
                  }
                  printf("%c", c);
                }
              } else if (regexec_res != 0 && flags[1] > 0) {
                regexed_str++;
                if (flags[3] > 0) {
                  regexed_succes = 1;
                  break;
                }
                if (flags[5] < 1 && flags[2] < 1 && flags[3] < 1) {
                  printf("%s:", argv[argv_count]);
                }
                if (flags[4] > 0 && flags[2] < 1 && flags[3] < 1) {
                  printf("%d:", in_file_str);
                }
                if (flags[2] < 1 && flags[3] < 1 && flags[8] < 1) {
                  printf("%s", scaned_string_arr);
                  printf("%c", c);
                } else if (flags[2] < 1 && flags[3] < 1 && flags[8] > 0) {
                  for (int count = pmatch[0].rm_so; count < pmatch[0].rm_eo;
                       count++) {
                    printf("%c", scaned_string_arr[count]);
                  }
                  printf("%c", c);
                }
              }
              scaned_string_len = 0;
              scaned_string_arr =
                  (char *)realloc(scaned_string_arr, 1 * sizeof(char));
              scaned_string_arr[0] = '\0';
            }
          }
          in_file_str++;
          regexec_res = 1;
          scaned_string_arr = (char *)realloc(
              scaned_string_arr, (scaned_string_len + 1) * sizeof(char));
          scaned_string_arr[scaned_string_len] = '\0';
          regexec_res =
              regexec(&regex_exp, scaned_string_arr, nmatch, pmatch, 0);
          if (regexec_res == 0 && flags[1] < 1) {
            regexed_str++;
            if (flags[3] > 0) {
              regexed_succes = 1;
            }
            if (flags[5] < 1 && flags[2] < 1 && flags[3] < 1) {
              printf("%s:", argv[argv_count]);
            }
            if (flags[4] > 0 && flags[2] < 1 && flags[3] < 1) {
              printf("%d:", in_file_str);
            }
            if (flags[2] < 1 && flags[3] < 1 && flags[8] < 1) {
              printf("%s", scaned_string_arr);
              printf("\n");
            } else if (flags[2] < 1 && flags[3] < 1 && flags[8] > 0) {
              for (int count = pmatch[0].rm_so; count < pmatch[0].rm_eo;
                   count++) {
                printf("%c", scaned_string_arr[count]);
              }
              printf("\n");
            }
          } else if (regexec_res != 0 && flags[1] > 0) {
            regexed_str++;
            if (flags[3] > 0) {
              regexed_succes = 1;
            }
            if (flags[5] < 1 && flags[2] < 1 && flags[3] < 1) {
              printf("%s:", argv[argv_count]);
            }
            if (flags[4] > 0 && flags[2] < 1 && flags[3] < 1) {
              printf("%d:", in_file_str);
            }
            if (flags[2] < 1 && flags[3] < 1 && flags[8] < 1) {
              printf("%s", scaned_string_arr);
              printf("\n");
            } else if (flags[2] < 1 && flags[3] < 1 && flags[8] > 0) {
              for (int count = pmatch[0].rm_so; count < pmatch[0].rm_eo;
                   count++) {
                printf("%c", scaned_string_arr[count]);
              }
              printf("\n");
            }
          }
          // */

          if (flags[2] > 0 && flags[3] < 1) {
            if (flags[5] < 1) {
              printf("%s:", argv[argv_count]);
            }
            printf("%d\n", regexed_str);
          }
          if (regexed_succes > 0 && flags[3] > 0) {
            printf("%s\n", argv[argv_count]);
          }
          free(scaned_string_arr);
          in_file_str = 0;
          fclose(file);
        } else {
          if (flags[6] < 1) {
            printf("%s: ", argv[argv_count]);
            puts("No such file or derictory");
          }
        }
      }
      argv_count++;
    }
    regfree(&regex_exp);
  }
}