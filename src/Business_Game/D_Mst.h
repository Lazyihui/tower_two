#ifndef  BUSINESS_D_MST_H__
#define  BUSINESS_D_MST_H__

#include "import.h"

void D_Mst_Spawn(Ctx* ctx, int typeID, Vector2 pos, float dt,int *outMstID) {

    E_Mst* mst = Factory_Create_Mst(ctx, typeID, pos, Vector2_New(0, -1));
    if (mst != NULL) {
        *outMstID= mst->ID;
        RP_Mst_Add(ctx->rp_mst, mst);
    }
}

void D_Mst_Move(Ctx* ctx, E_Mst* mst, float dt) {
    if (!mst->isLive) {
        return;
    }
    E_Mst_Move(mst, Vector2_New(0, -1), dt);
}

void D_Mst_Remove(Ctx *ctx,E_Mst*mst ){
    if(!mst->isLive){
        RP_Mst_Remove(ctx->rp_mst,mst);
    }
}
#endif