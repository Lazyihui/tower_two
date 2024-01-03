#ifndef D_MST_H__
#define D_MST_H__

#include <stdio.h>
#include <stdbool.h>
#include "E_Mst.h"
#include "E_cell.h"
#include "Factory.h"
#include "RP_Mst.h"
#include "Ctx.h"

void D_Mst_Spawn(Ctx* ctx, int typeID, Vector2 pos, float dt) {

    E_Mst* mst = Factory_Create_Mst(ctx, typeID, pos, Vector2_New(0, -1));

    if (mst != NULL) {
        RP_Mst_Add(ctx->rp_mst, mst);
    }
}

void D_Mst_Move(Ctx* ctx, E_Mst* mst, float dt) {
    if (!mst->isLive) {
        return;
    }
    E_Mst_Move(mst, Vector2_New(0, -1), dt);
}
#endif