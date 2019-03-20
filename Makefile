CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Wno-unused-parameter
CFLAGS += -Wno-unused-variable

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

run: main.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) main.c -o run

run-debug: main.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -ggdb3 main.c -o run-debug

memcheck: run-debug
	@valgrind $(VFLAGS) ./run-debug --row
	@echo "Memory check passed"