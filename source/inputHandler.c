#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "inputHandler.h"

int validateInput(char* inputString) {
    regex_t regex;
    char* pattern = "^\\s*([[:alnum:]_]*)\\s*\n$";

    if(regcomp(&regex, pattern, REG_EXTENDED) == 0) {
        printf("\nCompile successfully");
        int result = regexec(&regex, inputString, 0, NULL, 0);
        if(result == REG_NOMATCH) {
            printf("\nInput is invalid.");
        } else {
            printf("\nInput is valid.");
        }

    } else {
        printf("\nRegex Compilation Failed!\n");
        exit(1);
    }
}