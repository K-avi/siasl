#include "cmdline_interp.h"
#include "ast.h"
#include "lex.yy.h"


#include <stdio.h>
#include <string.h>



extern instruction * prog;


void interactive_interp( CELLMATRIX * environment, S_STACK * stack){
    
    char line[256];

    fflush(stdin); 
    fflush(stdout);

   // printf("before loop %p %p %p\n", prog, environment, stack);
    printf("welcome to the SIASL interactive interpreter!\n>>> ");
    while( fgets(line, 256, stdin)){
         
         fflush(stdin); 
         fflush(stdout);

         char * tmp= line; 

         while(*tmp==' '|| *tmp=='\t' || *tmp=='\n') ++tmp;
         if((*tmp)=='\0') {
            printf("\n>>> ");
            continue;
         }
       
         if(!strncmp(line, "quit", 4)){
            break;
         }
         
         yy_scan_string(line);

         yyparse(); 

         parsed_to_int(prog);
 
         exec_prgm(prog, environment, stack);

         
      
          free_instruct(prog);     
          yylex_destroy();

        if(strchr(line, '.')){
         printf("\n>>> ");
        }else {
         printf(">>> ");
        }
   }
   printf("bye!\n"); 
}