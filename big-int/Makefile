CC = gcc
INCLUDES = -Iinclude
LIBS = -Llib -ltesting-logger
ARCH =

# use for testing purposes
CFLAGS = -Wall -Wextra -pedantic -Wno-unused-command-line-argument -Wno-strict-prototypes -std=c17
DBGFLAGS = -g

SRC_FILES = big-uint mod
OBJ_FILES = $(addprefix obj/,$(SRC_FILES:=.o))

# variable to indicate use of pseudo-random generated numbers for testing
PRNG = 0

CYAN =\x1b[36m
WHITE=\x1b[0m

TEST_BINS = $(addprefix bin/test-, $(SRC_FILES))

all: $(TEST_BINS)

# Directory targets
obj:
	@mkdir obj
bin:
	@mkdir bin

# Binary Targets
bin/test-big-uint: obj/test-big-uint.o obj/big-uint.o | bin
	$(ARCH) $(CC) -o $@ $(CFLAGS) -Llib $^ -ltesting-logger

bin/test-mod: obj/test-mod.o obj/mod.o obj/big-uint.o | bin
	$(ARCH) $(CC) -o $@ $(CFLAGS) -Llib $^ -ltesting-logger

# Object targets
obj/%.o: src/%.c | obj
	$(ARCH) $(CC) -o $@ -c $(CFLAGS) $(DBGFLAGS) $(INCLUDES) -D PRNG=$(PRNG) $^

obj/test-%.o: tests/test-%.c | obj
	$(ARCH) $(CC) -o $@ -c $(CFLAGS) $(INCLUDES) -D PRNG=$(PRNG) $^

clean:
	@rm -rf bin
	@rm -rf obj
	@rm -rf big-int-pkg

test: PRNG=1
test: $(TEST_BINS)
	@echo && for f in $(TEST_BINS); do echo "$(CYAN)$$f$(WHITE)"; ASAN_OPTIONS=detect_leaks=1 $$f; echo; done

zip: all
	@mkdir big-int-pkg
	@cp -r lib bin obj src include Makefile-2 big-int-pkg
	@mv big-int-pkg/Makefile-2 big-int-pkg/Makefile
	@zip -r big-int-pkg.zip big-int-pkg > /dev/null
	@rm -rf big-int-pkg

