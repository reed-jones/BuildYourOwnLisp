#include <stdio.h>
#include <stdlib.h>


// for windows compatability
#include <string.h>

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


int main(int argc, char** argv)
{
//    Print Version Info
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    for(;;)
    {
        char* input = readline("lispy> ");
        add_history(input);

        printf("No you're a %s\n", input);
        free(input);
    }
    return 0;
}