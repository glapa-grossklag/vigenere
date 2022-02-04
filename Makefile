SRC    = $(wildcard *.c)
OBJ    = $(SRC:%.c=%.o)
BIN    = vigenere

CC     = clang -std=c11
CFLAGS = -Wall -Wextra -Wpedantic -g
LFLAGS =

.PHONY: all
all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

.PHONY: tidy
tidy:
	rm -f $(OBJ)

.PHONY: clean
clean: tidy
	rm -f $(BIN)

.PHONY: format
format:
	find . -name "*.[ch]" | xargs clang-format -i -style=file

%.o: %.c
	$(CC) $(CFLAGS) -c $<
