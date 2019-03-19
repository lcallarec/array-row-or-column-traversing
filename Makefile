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

memcheck: run
	@valgrind $(VFLAGS) ./run --col
	@echo "Memory check passed"