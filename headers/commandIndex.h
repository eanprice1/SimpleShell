#ifndef COMMANDINDEX_H_
#define COMMANDINDEX_H_
#include "pipe.h"

typedef struct commandIndex {
    int outRedirectBegin;
    int outRedirectEnd;
    int inRedirectBegin;
    int inRedirectEnd;
    int cmdBegin;
    int cmdEnd;
    int argBegin;
    int argEnd;
    int backgroundIndex;
    int pipeCount;
    int pipeSize;
    pipe* pipe;
}commandIndex;

void fillCommandIndex(commandIndex* cmdIndex, int pipeSize);

#endif
