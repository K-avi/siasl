#include "cells.h"
#include "ast.h"
#include "cmdline_interp.h"
#include "exec.h"
#include "stack.h"


#include "lex.yy.h"
#include "parser.tab.h"


#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>



#define PARSE (if(bfmode) {yyparse();} else {hhparse();})

extern instruction * prog;

int main(int argc, char ** argv){  


    u_char cmdline_mode=1, file_mode=0;


    u_char helpset=0;

    char* filename = NULL;
    int c;



    while ((c = getopt(argc, argv, "hcf:")) != -1) {
        
        switch (c) {
      
        case 'h':
            helpset=1;;
            break;
        case 'f':
            filename = optarg;
            cmdline_mode=0;
            file_mode=1;
            break;
        case 'c':
            
            cmdline_mode=1;
            file_mode=0;
            break;
      
        case '?':
            if (optopt == 'f')
            fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint(optopt))
            fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
            fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
       
            exit(-2);
        default:
            abort();
        }
    }

    if(helpset){

        printf("placeholder\n"); 

        exit(0);

    }

    
    /*initialising environment and stack ; prog is initialised by parser.tab.c*/
    CELLMATRIX * environment= init_mat(DEFAULT_ROWSIZE);
    S_STACK* stack= init_stack(STACK_SIZE);

    if (cmdline_mode) {

         interactive_interp(environment, stack);

         free_mat(environment);
         free_stack(stack);

         return 0;
    }else if(file_mode){

        
            yyin = fopen(filename, "r");
            if (!yyin) {
                perror("Could not open file");
                exit(-1);
            }
            yyparse();
            fclose(yyin);
      
        

        /*parsing everything*/
    
        parsed_to_int(prog);
        
        exec_prgm(prog, environment, stack);

        /*freeing everything after exec*/
        free_mat(environment);
        free_stack(stack);
        free_instruct(prog);
    

        yylex_destroy();
    }

    return 0;
}