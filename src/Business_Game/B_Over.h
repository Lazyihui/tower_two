#ifndef BUSINESS_BVER_H__
#define BUSINESS_BVER_H__

#include "import.h"

void B_Over_Enter(Ctx* ctx) {
    ctx->gameStatus = GAME_STATUS_OVER;
    ctx->rp_blt->count=0;
    ctx->rp_Cell->count=0;
    ctx->rp_mst->count=0;
    ctx->rp_tower->count=0;

}

#endif