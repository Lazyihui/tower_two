#ifndef RP_MST_H__
#define RP_MST_H__

#include <stdio.h>
#include <stdlib.h>
#include "import.h"
//增删改查
typedef struct RP_Mst {
    E_Mst** all;
    int count;
} RP_Mst;

void RP_Mst_Init(RP_Mst* rp_mst) {
    rp_mst->all = (E_Mst**)calloc(1000, sizeof(E_Mst*));
    rp_mst->count = 0;
}

void RP_Mst_Free(RP_Mst* rp_mst) {
    for (int i = 0; i < rp_mst->count; i++) {
        free(rp_mst->all[i]);
    }
    free(rp_mst->all);
    free(rp_mst);
}

void RP_Mst_Add(RP_Mst* rp_mst, E_Mst* mst) {
    rp_mst->all[rp_mst->count++] = mst;
}

void RP_Mst_Remove(RP_Mst *rp_mst,E_Mst *mst){
    for(int i=0;i<rp_mst->count;i++){
        if(rp_mst->all[i]->ID==mst->ID){
            rp_mst->all[i]=rp_mst->all[rp_mst->count];
            rp_mst->count--;
            return;
            
        }
    }

}

#endif