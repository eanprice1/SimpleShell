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
    pipe* pipe;
}commandIndex;

#endif