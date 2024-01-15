#ifndef BUSINESS_D_TOWER_H__
#define BUSINESS_D_TOWER_H__

#include "import.h"

void D_Tower_Spraw(Ctx* ctx, int typeID, Vector2 pos, 
                   int* outClickTowerID) {

    E_Tower* tower = Factory_Create_Tower(ctx, typeID, pos);
    if (tower != NULL) {
        tower->isLive = true;
        *outClickTowerID = tower->ID;
        RP_Tower_Add(ctx->rp_tower, tower);
    }
}

#endif