#include <stdio.h>

// User input buffer. Size of 2048
static char input[2048];

int main(int argc, char** argv)
{
//    Print Version Info
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    for(;;)
    {
//        Output our prompt
        fputs("lispy> ", stdout);

//        read user input
        fgets(input, 2048, stdin);

//        echo back to user
        printf("No you're a %s", input);
    }
    return 0;
}