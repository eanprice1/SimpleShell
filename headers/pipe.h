#ifndef PIPE_H_
#define PIPE_H_

typedef struct pipe {
    int begin;
    int end;
}pipe;

void fillPipe(pipe* pipe);

#endif