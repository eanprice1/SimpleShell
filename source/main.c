#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputHandler.h"

int main(void) {
    size_t len = 100;
    char* input = (char*) malloc(100 * sizeof(char));
    while(1){
        printf("\nIUPUI> ");
        int numChars = getline(&input, &len, stdin);
        if(numChars < 0) {
            printf("\nAn error occurred while reading input.");
            continue;
        }
        validateInput(input);
    }
    free(input);
}