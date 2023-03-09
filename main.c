#include "cells.h"
#include "ast.h"
#include "cmdline_interp.h"
#include "exec.h"
#include "parser.tab.h"
#include "stack.h"
#include "lex.yy.h"


#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>



extern instruction * prog;

int main(int argc, char ** argv){  


    u_char printAst = 0, cmdline_mode=1, file_mode=0;
    char* filename = NULL;
    int c;

    /*initialising environment and stack ; prog is initialised by parser.tab.c*/
    CELLMATRIX * environment= init_mat(DEFAULT_ROWSIZE);
    S_STACK* stack= init_stack(STACK_SIZE);

    while ((c = getopt(argc, argv, "cpf:")) != -1) {
        
        switch (c) {
        case 'p':
            printAst = 1;
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
            free_mat(environment);
            free_stack(stack);
            exit(-2);
        default:
            free_mat(environment);
            free_stack(stack);
            abort();
        }
    }

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
    if (printAst) {
        printf("program at exit: \n");
        printprgm(prog);
        printf("env at exit: \n");
        print_mat(environment);
    }

    

    return 0;
}