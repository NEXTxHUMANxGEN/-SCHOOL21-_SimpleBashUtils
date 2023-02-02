all: s21_grep

s21_grep: 
	gcc -Wall -Wextra -Werror main_s21_grep.c -o s21_grep

rebuild:
	rm s21_grep
	gcc -Wall -Wextra -Werror main_s21_grep.c -o s21_grep

clang_test:
	clang-format -style=google -n *.c 

test:
	sh s21_grep_test.sh

valgrind_test:
	valgrind --leak-check=full --track-origins=yes -s ./s21_grep -e as text_file -f file_for_regex -nv