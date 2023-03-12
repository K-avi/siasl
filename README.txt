This is the repo of the siasl interpreter for the SIASL language!
Which stands for Siasl Is A Silly Language !

siasl is an esolang that I make for fun. 
It thus doesn't have any practical interrest that I can think of. 

In order to build the siasl interpreter you will need gcc , flex ,bison and make.

SIASL exists to lay the fundation of (SIASL)² which will be way sillier and funnier than normal SIASL ! 
it also exists to help me get more familiar with bison/flex parsing. 

I don't claim that it's design is particularly good and I make it for fun ! 

SIASL supports 13 instructions that can be written as brainfuck-like symbols they can also be 
written as hexadecimal number if siasl is called with -x.

NOTE : the hexadecimal parsing is currently very bad ; siasl has way worse performance w it 
I will fix this at some point.

the siasl instructions are :

1|# is the neutral instruction. 

2|< is "go to the cell on the left " curcell= curcell->left
3|> is "go to the cell on the right" curcell=curcell->right
4|^ is "go to the cell on the top" curcell=curcell->up
5|v is "go to the cell on the bootom" curcell= curcel->down
 
6|+ is "increment" curcell->value+=1
7|- is "decrelent"  curcell->value-=1
8|* is "mutliply by 2" curcell->value*=2
9|/ is "integer division by 2"  curcell->value/=2

a|A|, is "read" getchar(&(curcell->value))
b|B|. is "print out" printf("%c", curcell->value)
c|C|[ is "start loop while the value isn't 0" (while (curcell->value){
d|D|] is "stop loop" }

SIASL currently supports the options -c , -h, -x , -f ,-s 

-c : (default) interactive command line interpreter mode
-f : file mode reads a siasl or hexsiasl file and executes the instructions in it.
-s : (default) enables support for SIASL's brainfuck-like symbols.
-x : enables support for hexadecimal symbols.
-h : prints out a help paragraph

NB: the -f and -c options are incompatible and the last option called is the one that 
    will be used. 
    similarly, the -x and -s options are incompatible.


SIASL's inspirations: 


-the brainfuck language : cf https://esolangs.org/wiki/Brainfuck
-the unary language : cf https://esolangs.org/wiki/Unary

When starting SIASL I did not if 2d brainfucks were a thing but I assumed they were; 
if you want to learn about those I suggest checking out these pages: 

https://esolangs.org/wiki/Befunge
https://esolangs.org/wiki/Generic_2D_Brainfuck

https://esolangs.org/wiki/BF%2BBF (more powerfull than a "2d brainfuck" but still really cool!!!)


SIASL used some of the code of the brainflex interpreter by lagerfeuer. ( https://github.com/lagerfeuer )

the lexer.l and parser.y files were based on the lexer.l and grammar.y files from his project! 
Check it out here :
https://github.com/lagerfeuer/brainflex/blob/main/src/grammar.y
https://github.com/lagerfeuer/brainflex/blob/main/src/lexer.l 