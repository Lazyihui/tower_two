#ifndef REPOSITORY_RP_TOWER_H__
#define REPOSITORY_RP_TOWER_H__

#include "import.h"

typedef struct RP_Tower {

    E_Tower** all;
    int count;

} RP_Tower;

// 增删改查
void RP_Tower_Init(RP_Tower* rp) {
    rp->all = (E_Tower**)calloc(20, sizeof(RP_Tower));
    rp->count = 0;
}

void RP_Tower_Free(RP_Tower* rp) {
    for (int i = 0; i < rp->count; i++) {
        free(rp->all[i]);
    }
    free(rp->all);
    free(rp);
}

void RP_Tower_Add(RP_Tower *rp,E_Tower *tower){
    rp->all[rp->count++]=tower;
}


#endif