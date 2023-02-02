all: s21_cat

s21_cat: 
	gcc -Wall -Wextra -Werror main_s21_cat.c -o s21_cat

test:
	sh s21_cat_test.sh
clang_test:
	clang-format -style=google -n *.c

valgrind_test:
	valgrind --leak-check=full --track-origins=yes -s ./s21_cat -nbs try it text_file --t - q str_file --i
rebuild:
	rm s21_cat
	gcc -Wall -Wextra -Werror main_s21_cat.c -o s21_cat