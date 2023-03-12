/* based on the brainflex lex.l file https://github.com/lagerfeuer/brainflex/blob/main/src/lexer.l */

%option header-file="lex.hh.h"
%option noinput nounput noyywrap

%option prefix="hh"
%{
  #include <stdio.h>
  #include <stdlib.h> 

%}

%%

[ \t\n]+    { ; }
"0"         { }
"1"         { return 1; }
"2"         { return TOKEN(RIGHT); }
"3"         { return TOKEN(LEFT); }
"4"         { return TOKEN(UP); }
"5"         { return TOKEN(DOWN); }
"6"         { return TOKEN(PLUS); }
"7"         { return TOKEN(MINUS); }
"8"         { return TOKEN(MULT);}
"9"         { return TOKEN(DIV);}
"a"|"A"         { return TOKEN(LBRACKET); }
"b"|"B"         { return TOKEN(RBRACKET); }
"c"|"C"         { return TOKEN(NEUTRAL); }
"d"|"D"         { return TOKEN(NEUTRAL); }
"e"|"E"         { return TOKEN(NEUTRAL); }
"f"|"F"         { return TOKEN(NEUTRAL); }

.           { ; }

%%