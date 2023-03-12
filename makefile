TARGET := siasl

TEST := test
CC := gcc
CFLAGS := -O2 -Wall -Wextra -Wpedantic
CLIBS := -lfl

LEX := flex
LFLAGS :=

YACC := bison
YFLAGS := -v -d

SRCS := exec.c ast.c cells.c stack.c cmdline_interp.c

all: $(TARGET)

debug: CFLAGS += -DDEBUG -g
debug: LFLAGS += --debug
debug: YFLAGS += --debug
debug: $(TARGET)

$(TARGET): lex.yy.c parser.tab.c $(SRCS) main.c
	$(CC) $(CFLAGS) $^ -o $(TARGET) $(CLIBS)


$(TEST): lex.yy.c parser.tab.c $(SRCS) main_test.c
	$(CC) $(CFLAGS) $^ -o $(TEST) $(CLIBS)

lex.yy.c lex.yy.h: lexer.l parser.tab.h
	$(LEX) $(LFLAGS) $<


parser.tab.c parser.tab.h: parser.y
	$(YACC) $(YFLAGS) $<

clean:
	rm -f parser.tab.* parser.output lex.*.* $(TARGET) $(TEST)
.PHONY: clean
