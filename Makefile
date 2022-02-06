SRC    = $(wildcard *.c)
HDR    = $(wildcard *.h)
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
format: .clang-format
	clang-format -i -style=file $(SRC) $(HDR)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
