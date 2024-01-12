#ifndef BUSINESS_UI_H__
#define BUSINESS_UI_H__

#include "import.h"

void D_UI_Tower_Open(Ctx* ctx, Vector2 pos,int cellID,void (*onClickStartHandle)(void)) {

    APP_UI_PanelTower_Open(ctx->ctx_UI, pos,cellID ,onClickStartHandle);

    int manifest[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        int typeID = manifest[i];
        TM_Tower* towerTM = Template_GetTower(ctx->tpl, typeID);

        APP_UI_PanelTower_Add(ctx->ctx_UI, towerTM->typeID, towerTM->iconColor);

        assert(towerTM!=NULL);

    }

}

void D_UI_Tower_Close(Ctx* ctx) {
    APP_UI_PanelTower_Close(ctx->ctx_UI);
}

void D_UI_Tower_toggle(Ctx* ctx, Vector2 pos,int cellID,void (*onClickStartHandle)(void)) {
    if (APP_UI_PanelTower_IsOpen(ctx->ctx_UI)) {
        D_UI_Tower_Close(ctx);
    } else {
        D_UI_Tower_Open(ctx,pos ,cellID,onClickStartHandle);
    }
}

#endif