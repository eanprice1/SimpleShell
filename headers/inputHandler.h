#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_
#include "commandIndex.h"

int isExitRequested(char* inputString);
int isEmptyCommand(char* inputString);
int validateInput(int numChars, char* inputString, commandIndex* cmdIndex);
int skipWhitespace(int curIndex, int numChars, char* inputString);
int iterateToStringEnd(int curIndex, char* inputString);

#endif