//
// Created by Worker on 24.12.2023.
//

#ifndef ADS_STRUCTURES_FILEQUEUE_H
#define ADS_STRUCTURES_FILEQUEUE_H

#include "../queueArray/queueArray.h"

#define FileOk 0
#define FileEnd 1
#define FileNotMem 2

extern int FileError;

typedef struct File {
    queueArray Read;
    queueArray NotRead;
} File;

void FileInit(File *F);

void PutFile(File *F, baseTypeQueueArray E);

void GetFile(File *F, baseTypeQueueArray *G);

void FileBeginPtr(File *F);

#endif //ADS_STRUCTURES_FILEQUEUE_H
