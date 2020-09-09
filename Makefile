all: pa1.c
	gcc -Wall -Werror -fsanitize=address pa1.c -o pa1

clean:
	rm pa1
