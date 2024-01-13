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

void D_Blt_Move(Ctx* ctx, float dt) {
    for (int i = 0; i < ctx->rp_blt->count; i++) {
        E_Blt* blt = ctx->rp_blt->all[i];
        if (blt->isLive) {

            E_Blt_Move(blt, blt->moveAxis, dt);

            E_Mst* mst = FindNearestMst(ctx, blt->pos, blt->hurtRange);
            if (mst != NULL) {
                // 这里可以写blt 和mst的交叉检测
                bool isInside = IsCirlceInsideCircle(blt->radius, mst->radius,
                                                     blt->pos, mst->pos);
                if (isInside) {
                    blt->isLive = false;
                    mst->hp -= 1;
                    if (mst->hp <= 0) {
                        mst->isLive = false;
                    }
                }
                E_Blt_InputByTarget(blt, mst->pos);
            }
        }
    }
}

// blt消失//可以把for循环改到外面去
void D_Blt_Fade(Ctx* ctx) {
    for (int i = ctx->rp_blt->count - 1; i >= 0; i--) {
        E_Blt* blt = ctx->rp_blt->all[i];
        if (blt->isInside) {
            ctx->rp_blt->all[i] = ctx->rp_blt->all[ctx->rp_blt->count - 1];
            ctx->rp_blt->all[ctx->rp_blt->count - 1] = blt;
            ctx->rp_blt->count -= 1;
        }
    }
}

#endif