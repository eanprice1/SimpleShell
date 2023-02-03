#include <stdio.h>
#include <stdlib.h>
#include "inputHandler.h"

int main(void) {
    char* inputString = (char*) malloc(200 * sizeof(char));
    while(1){
        printf("\nIUPUI> ");
        scanf("%s", inputString);
        validateInput(inputString);
    }
}