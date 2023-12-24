//
// Created by Worker on 24.12.2023.
//

#include "fileQueue.h"

void FileInit(File *F) {
    QueueArrayInit(&F->Read);
    QueueArrayInit(&F->NotRead);
    FileError = queueArrayError;
}

void PutFile(File *F, baseTypeQueueArray E) {
    if (F->NotRead.queueArrayDynamicSize < queueArraySize) {
        queueArrayPut(&F->NotRead, E);
        FileError = queueArrayError;
    } else {
        FileError = FileNotMem;
    }
}

void GetFile(File *F, baseTypeQueueArray *G) {
    if (F->NotRead.queueArrayDynamicSize > 0) {
        queueArrayGet(&F->NotRead, G);
        if (F->Read.queueArrayDynamicSize < queueArraySize) {
            queueArrayPut(&F->Read, *G);
            FileError = queueArrayError;
        } else {
            FileError = FileNotMem;
        }
    } else {
        FileError = FileEnd;
    }
}

void FileBeginPtr(File *F) {
    baseTypeQueueArray G;
    while (F->NotRead.queueArrayDynamicSize > 0) {
        GetFile(F, &G);
        queueArrayPut(&F->Read, G);
    }

    while (F->Read.queueArrayDynamicSize > 0) {
        queueArrayGet(&F->Read, &G);
        PutFile(F, &G);
    }
}