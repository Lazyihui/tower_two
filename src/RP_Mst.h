#ifndef RP_MST_H__
#define RP_MST_H__

#include <stdio.h>
#include <stdlib.h>
#include "E_Mst.h"

typedef struct RP_Mst {
    E_Mst** all;
    int count;
} RP_Mst;

void RP_Mst_Init(RP_Mst* rp) {
    rp->all = (E_Mst**)calloc(1000, sizeof(E_Mst*));
    rp->count = 0;
}

void RP_Mst_Free(RP_Mst* rp) {
    for (int i = 0; i < rp->count; i++) {
        free(rp->all[i]);
    }
    free(rp->all);
    free(rp);
}

void RP_Mst_Add(RP_Mst* rp, E_Mst* mst) {
    assert(mst!=NULL);
    printf("a");
        rp->all[rp->count++] = mst;

}

#endif