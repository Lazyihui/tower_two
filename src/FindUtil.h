#ifndef FINDUTIL_H__
#define FINDUTIL_H__

#include "Ctx.h"

// 找到最近的mst

E_Mst* FindNearestMst(Ctx* ctx, Vector2 pos, float range) {
    E_Mst* mstRes = NULL;
    float nearest = 10000;
    range *= range;
    for (int i = 0; i < ctx->rp_mst->count; i++) {
        /* code */
        E_Mst* mst = ctx->rp_mst->all[i];
        float tmp = Vector2DistanceSqr(pos, mst->pos);
        if (tmp <= range && tmp < nearest) {
            mstRes = mst;
            nearest = tmp;
        }
    }
    return mstRes;
}

#endif