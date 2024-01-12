#ifndef REPOSITOR_RP_BLT_H__
#define REPOSITOR_RP_BLT_H__

#include "import.h"

typedef struct RP_Blt {
    E_Blt** all;
    int count;
} RP_Blt;

void RP_Blt_Inti(RP_Blt* rp) {
    rp->all = (E_Blt**)calloc(1000, sizeof(E_Blt));
    rp->count = 0;
}

void RP_Blt_Free(RP_Blt* rp) {
    for (int i = 0; i < rp->count; i++) {
        free(rp->all[i]);
    }
    free(rp->all);
    free(rp);
}

void RP_Blt_Add(RP_Blt* rp, E_Blt* blt) {
    rp->all[rp->count++] = blt;
}

#endif