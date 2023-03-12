/* based on brainflex grammar.y file https://github.com/lagerfeuer/brainflex/blob/main/src/grammar.y */
%define api.prefix {hh}

%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <ctype.h>
  #include <unistd.h>

  #include "ast.h"

  extern FILE* hhin;
  extern int hhlex(void);
  extern int hhparse(void);
  void hherror(const char *s);

  struct instruction * prog;
%}

%union {
  struct instruction* instruction;
  int token;
}

%token <token> PRINT READ LEFT RIGHT UP DOWN PLUS MINUS MULT DIV NEUTRAL
%token <token> LBRACKET RBRACKET

%type <instruction> program stmts stmt loop
%type <token> op

%start program

%%

program
  : stmts { prog = $$; }
;

stmts
  : stmt        { $$ = $1; }
  | stmts hstmt  { add_instruction($$ = $1, $2); }
;

stmt
  : loop { $$ = $1; }
  | op   { $$ = mkinstruction($1); }
;

loop
  : LBRACKET stmts RBRACKET {
      $$ = mkinstruction($1);
      $$->next = $2;
      $$->other = mkinstruction($3);
      add_instruction($$->next, $$->other);
      $$->other->other = $$;
    }
;

op
  : PRINT
  | READ
  | LEFT
  | RIGHT
  | UP
  | DOWN
  | PLUS
  | MINUS
  | MULT
  | DIV
  | NEUTRAL
;

%%


void yyerror(const char* s) {
  fprintf(stderr, "yyerr: %s\n", s);
}
