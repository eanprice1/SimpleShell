#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "inputHandler.h"
#include "commandIndex.h"

int isExitRequested(char* inputString) {
    regex_t regex;
    char* pattern = "^\\s*exit\\s*";
    if(regcomp(&regex, pattern, REG_EXTENDED) == 0) {
        int result = regexec(&regex, inputString, 0, NULL, 0);
        if(result == 0){
            return 1;
        } else if(result == REG_NOMATCH) {
            return 0;
        } else {
            printf("\nRegex Match Error!\n");
            exit(1);
        }
    }
}

int isEmptyCommand(char* inputString) {
    regex_t regex;
    char* pattern = "^\\s*$";
    if(regcomp(&regex, pattern, REG_EXTENDED) == 0) {
        int result = regexec(&regex, inputString, 0, NULL, 0);
        if(result == 0){
            return 1;
        } else if(result == REG_NOMATCH) {
            return 0;
        } else {
            printf("\nRegex Match Error!\n");
            exit(1);
        }
    }
}

int validateInput(int numChars, char* inputString, commandIndex* cmdIndex) {
    int curIndex = 0;

    curIndex = iterateWhiteSpace(curIndex, inputString);

    //found first character
    switch(inputString[curIndex]) {
        case '<':
            return 0;
        case '|':
            return 0;
        case '>':
            return 0;
        case '&':
            return 0;
        default:
            cmdIndex->cmdBegin = curIndex;
            curIndex++;
            break;
    }

    while(inputString[curIndex] != ' ' && curIndex < numChars) {
        curIndex++;
    }
    //found last character of cmd
    cmdIndex->cmdEnd = curIndex - 1;
    if(curIndex == numChars){
        return 1;
    }

    //search for args
    while(curIndex < numChars) {
        curIndex = iterateWhiteSpace(curIndex, inputString);

        char curChar = inputString[curIndex];
        if(curChar == '<'){
            if(cmdIndex->inRedirectBegin == 0 && cmdIndex->pipe[0].begin == 0 &&
            cmdIndex->outRedirectBegin == 0 && cmdIndex->backgroundIndex == 0) {
                cmdIndex->inRedirectBegin = curIndex;
                break;
            } else {
                return 0;
            }
        } else if(curChar == '|') {
            if(cmdIndex->outRedirectBegin == 0 && cmdIndex->backgroundIndex == 0) {
                cmdIndex->pipe[0].begin = curIndex;
                break;
            } else {
                return 0;
            }
        } else if(curChar == '>') {
            if(cmdIndex->outRedirectBegin == 0 && cmdIndex->backgroundIndex == 0) {
                cmdIndex->outRedirectBegin = curIndex;
                break;
            } else {
                return 0;
            }
        } else if(curChar == '&') {
            //check for extra characters
            if("no extra characters") {
                cmdIndex->backgroundIndex = curIndex;
                return 1;
            } else {
                return 0;
            }
        } else if(curChar == '\n') {
            return 1;
        } else {
            if(cmdIndex->inRedirectBegin == 0 && cmdIndex->pipe[0].begin == 0 && 
            cmdIndex->outRedirectBegin == 0 && cmdIndex->backgroundIndex == 0) {
                if(cmdIndex->argBegin == 0) {
                    cmdIndex->argBegin = curIndex;
                }
                curIndex++;
                //find end index
                while(inputString[curIndex] != ' ' && inputString[curIndex] != '<' &&
                inputString[curIndex] != '|' && inputString[curIndex] != '>' &&
                inputString[curIndex] != '&' && curIndex < numChars) {
                    curIndex++;
                }
                cmdIndex->argEnd = curIndex - 1;
                if(curIndex == numChars) {
                    return 1;
                }
            } else {
                return 0;
            }
        }
    }

    return 1;
}

int iterateWhiteSpace(int curIndex, char* inputString) {
    while(inputString[curIndex] == ' '){
        curIndex++;
    }
    return curIndex;
}

int findNextString(int curIndex, char* inputString) {

}




int iterateToStringEnd(int curIndex, char* inputString) {
    while(inputString[curIndex] != ' ') {
        if(inputString[curIndex] == '\0') {
            break;
        }
        printf("\n%c", inputString[curIndex]);
        curIndex++;
    }
    return curIndex;
}

// switch(inputString[curIndex]) {
// case '<':
//     cmdIndex->inRedirectBegin = curIndex;
//     //find end
//     break;
// case '|':
//     cmdIndex->pipe[0].begin = curIndex;
//     //find end for index 0
//     break;
// case '>':
//     cmdIndex->outRedirectBegin = curIndex;
//     //find end
//     break;
// case '&':
//     cmdIndex->backgroundIndex = curIndex;
//     //check for extra characters
//     break;
// default:
//     if(cmdIndex->argBegin == 0) {
//         cmdIndex->argBegin = curIndex;
//     }
//     curIndex++;
//     break;
// }

// int validateInput(char* inputString) {
//     regex_t regex;
//     char* pattern = "^\\s*([[:alnum:]_]*)(\\s+[^<>|][[:alnum:]]*)*\\s*\n$";
//     regmatch_t pmatch[3];

//     if(regcomp(&regex, pattern, REG_EXTENDED) == 0) {
//         printf("\nCompile successfully");
//         int result = regexec(&regex, inputString, 3, pmatch, 0);
//         if(result == REG_NOMATCH) {
//             printf("\nInput is invalid.");
//         } else {
//             printf("\nInput is valid.");
//             for(int i = 0; i < regex.re_nsub + 1; i++) {
//                 printf("\n%d", pmatch[i].rm_so);
//                 printf("\n%d", pmatch[i].rm_eo);
//             }
//         }

//     } else {
//         printf("\nRegex Compilation Failed!\n");
//         exit(1);
//     }
// }