#include <stdio.h>
#include <stdlib.h>
#include "commandIndex.h"

void fillCommandIndex(commandIndex* cmdIndex, int pipeSize) {
    cmdIndex->outRedirectBegin = 0;
    cmdIndex->outRedirectEnd = 0;
    cmdIndex->inRedirectBegin = 0;
    cmdIndex->inRedirectEnd = 0;
    cmdIndex->cmdBegin = 0;
    cmdIndex->cmdEnd = 0;
    cmdIndex->argBegin = 0;
    cmdIndex->argEnd = 0;
    cmdIndex->backgroundIndex = 0;
    cmdIndex->pipeCount = 0;
    cmdIndex->pipe = (pipe*) malloc(pipeSize * sizeof(pipe));
    for(int i = 0; i < pipeSize; i++) {
        fillPipe(&cmdIndex->pipe[i]);
    }
}