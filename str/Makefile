DEPS = string.c
CFLAGS = -g -Wall -Wextra -ansi -pedantic

bin/examples: examples.c $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@
run: bin/examples
	./bin/examples
