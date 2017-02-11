#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpc.h"

static char buffer[2048];

//fake readline function for windows
char* readline(char* prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

// fake add history for windows
void add_history(char* unused) {};


int main(int argc, char** argv) {

    mpc_parser_t* Protocol      = mpc_new("protocol");
    mpc_parser_t* Subdomain     = mpc_new("subdomain");
    mpc_parser_t* Domain        = mpc_new("domain");
    mpc_parser_t* TLD           = mpc_new("tld");
    mpc_parser_t* Website          = mpc_new("website");
    mpc_parser_t* FullWebsite      = mpc_new("fullwebsite");

    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                                \
      protocol    : \"http://\" | \"https://\";                      \
      subdomain   : \"www.\";                                        \
      domain      : /[a-z]+/;                                        \
      tld         : \".com\" | \".ca\";                              \
      website     : <protocol>? <subdomain>* <domain> <tld>;         \
      fullwebsite : <website>*;                                      \
    ",
              Protocol, Subdomain, Domain, TLD, Website, FullWebsite);

    puts("Lispy Version 0.0.0.0.2");
    puts("Press Ctrl+c to Exit\n");

    for(;;)
    {
        char* input = readline("lisyp> ");
        add_history(input);

//        attempt to parse user input
        mpc_result_t r;

//        stdin is part of the error message.
        if(mpc_parse("<stdin>", input, FullWebsite, &r))
        {
//            on success print and delete the AST
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        }
        else
        {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }
        free(input);
    }

    mpc_cleanup(4, Protocol, Domain, Website, FullWebsite);

    return 0;

}