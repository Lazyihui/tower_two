#ifndef BUSINESS_UI_H__
#define BUSINESS_UI_H__

#include "import.h"

void D_UI_Tower_Open(Ctx* ctx, void (*onClickStartHandle)(void)) {

    APP_UI_PanelTower_Open(ctx->ctx_UI, Vector2Zero(), onClickStartHandle);
    APP_UI_PanelTower_Add(ctx->ctx_UI, 1, GREEN);
    APP_UI_PanelTower_Add(ctx->ctx_UI, 5, YELLOW);
    APP_UI_PanelTower_Add(ctx->ctx_UI, 8, BLUE);
}

void D_UI_Tower_Close(Ctx* ctx) {
    APP_UI_PanelTower_Close(ctx->ctx_UI);
}

void D_UI_Tower_toggle(Ctx* ctx, void (*onClickStartHandle)(void)) {

    if (APP_UI_PanelTower_IsOpen(ctx->ctx_UI)) {
        D_UI_Tower_Close(ctx);
    } else
        (D_UI_Tower_Open(ctx, onClickStartHandle));
}

#endif