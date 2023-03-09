This is the repo of the siasl language; which stands for Siasl Is A Silly Language 

siasl is an esolang that I want to make for fun. It thus doesn't have any practical interrest that I can think of. 

Siasl's design has 2 main ideas: 

-a program is a bunch of instruction that will modify the state of cellular automatons 
-each instruction must be 1 byte or shorter. 

Instructions thus look kinda goofy! 

a siasl instruction is a combinations of 2 4 bits elements. 

each instruction can be executed on its own or be combined with another instruction to make a new one: 


0 is the neutral instruction. 

1 is "go to the cell on the right " curcell= curcell->right
2 is "go to the cell on the left" curcell=curcell->left
3 is "go to the cell on the top" curcell=curcell->up
4 is "go to the cell on the bootom" curcell= curcel->down
 
5 is "add" curcell->value+=?
6 is "substract"  curcell->value-=?
7 is "mutliply" curcell->value*=?
8 is "divide"  curcell->value/=?

9 is "print out" printf("%c", curcell->value)
10 is "read" getchar(&(curcell->value))
11 is "start loop while the value isn't 0" (while (curcell->value){
12 is "stop loop" }

0 | 4 > add curval with the val on the right and store it in curval

examples of how it would actually works: 

first of the "do nothing" instruction is neutral

Each command supports the "modes" which make the command change their behavior