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
        
        // initialize cmdIndex and fill with default values
        commandIndex cmdIndex;
        fillCommandIndex(&cmdIndex, 10);
        
        int isValid = validateInput(numChars, input, &cmdIndex);
        if(isValid) {
            printf("\nValid");
        } else {
            printf("\nNot Valid");
        }

        free(cmdIndex.pipe);
    }
    free(input);
    printf("\nExited Shell.");
}