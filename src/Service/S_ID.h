#ifndef S_ID_H__
#define S_ID_H__

// S Service
typedef struct S_ID {
    int cellIDRecord;
    int mstIDRecord;
    int towerRecord;
} S_ID;

void S_ID_Init(S_ID* s_id) {
    s_id->cellIDRecord = 0;
    s_id->mstIDRecord = 0;
    s_id->towerRecord = 0;
}

#endif