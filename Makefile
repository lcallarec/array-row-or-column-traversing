CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Wno-unused-parameter
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-missing-field-initializers

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

OS = $(shell uname -s)
EXTLIB=
ifeq ($(OS), Darwin)
	EXTLIB += "-largp"
endif

traverse: main.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) $(EXTLIB) main.c -o traverse

clean:
	@rm -f traverse traverse-debug

traverse-debug: main.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) $(EXTLIB) -ggdb3 main.c -o traverse-debug

memcheck: traverse-debug
	@valgrind $(VFLAGS) ./traverse-debug --row
	@echo "Memory check passed"