#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputHandler.h"
#include "commandIndex.h"

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

        // checks for empty input
        if(isEmptyCommand(input)) {
            continue;
        }
        
        // checks for exit command
        if(isExitRequested(input)){
            break;
        }
        
        commandIndex cmdIndex = {0, 0, 0, 0, 0, 0, 0, 0, 0, (pipe*) malloc(10 * sizeof(pipe))};
        validateInput(numChars, input, &cmdIndex);

        free(cmdIndex.pipe);
        free(&cmdIndex);
    }
    free(input);
    printf("\nExited Shell.");
}