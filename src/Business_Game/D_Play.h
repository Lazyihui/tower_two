#ifndef BUSINESS_D_PLAY_H__
#define BUSINESS_D_PLAY_H__

#include "import.h"

void D_Play_Tick(Ctx* ctx, float dt) {
    ctx->time += dt;
    if (ctx->gold <= 100) {
        ctx->gold += dt * 2.0f;
    }
}

#endif