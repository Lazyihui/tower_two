#ifndef BUSINESS_D_BLT_H__
#define BUSINESS_D_BLT_H__

#include "import.h"

void D_Blt_Spawn(Ctx* ctx, int typeID, Vector2 moveAxis, Vector2 pos) {
    E_Blt* blt = Factory_Create_Blt(ctx, typeID, moveAxis, pos);
    if (blt != NULL) {
        RP_Blt_Add(ctx->rp_blt, blt);
        blt->isLive = true;
    }
}

#endif