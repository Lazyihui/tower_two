#ifndef BUSINESS_B_GAME_H__
#define BUSINESS_B_GAME_H__

#include "D_Cell.h"
#include "D_Mst.h"
#include "import.h"
#include "D_UI.h"

void UI_PanelTower() {
    // Plog("UI_PanelTower");
    printf("UI_PanelTower");
}

void B_Game_Enter(Ctx* ctx) {

    // 生成格子
    for (int y = -26; y <= 26; y += std_cell) {
        Vector2 pos = Vector2_New(-8, y);
        pos = Vector2Scale(pos, std_cell);
        D_Cell_Spawn(ctx, 1, pos);
    }
    for (int y = -26; y <= 26; y += std_cell) {
        Vector2 pos = Vector2_New(6, y);
        pos = Vector2Scale(pos, std_cell);
        D_Cell_Spawn(ctx, 1, pos);
    }
}

void B_Game_Tick(Ctx* ctx, float dt) {
    // mst 生成
    ctx->mstSpawnTimer -= dt;
    if (ctx->mstSpawnTimer <= 0) {
        D_Mst_Spawn(ctx, 1, Vector2_New(0, 28 * std_cell), dt);
        ctx->mstSpawnTimer = ctx->mstSpawnInterval;
    }
    // 移动
    for (int i = 0; i < ctx->rp_mst->count; i++) {
        // 加一个i取一个*
        E_Mst* mst = ctx->rp_mst->all[i];
        D_Mst_Move(ctx, mst, dt);
    }
    // mst的血量减为0的情况
    for (int i = 0; i < ctx->rp_mst->count; i++) {
        E_Mst* mst = ctx->rp_mst->all[i];
        if (mst->pos.y <= -18 * std_cell) {
            mst->isLive = false;
        }
    }
    // mst移除
    for (int i = ctx->rp_mst->count - 1; i >= 0; i--) {
        E_Mst* mst = ctx->rp_mst->all[i];
        if (!mst->isLive) {
            ctx->rp_mst->all[i] = ctx->rp_mst->all[ctx->rp_mst->count - 1];
            ctx->rp_mst->all[ctx->rp_mst->count - 1] = mst;
            ctx->rp_mst->count -= 1;
        }
    }
    // cellToTower
    for (int i = 0; i < ctx->rp_Cell->count; i++) {
        E_cell* cell = ctx->rp_Cell->all[i];
        E_Input* input = ctx->input;
        cell->isClick = E_cell_IsMouseInsideClick(cell, ctx->input->mouseWorldPos, ctx->input->isMouseDown);

        if (cell->isClick) {
            // cell->isCellToTower = true;
            D_UI_Tower_toggle(ctx, Vector2_New(cell->pos.x - 1.5 * std_cell, cell->pos.y), &UI_PanelTower);
        }

        // for (int j = 0; ctx->ctx_UI->pn_towerMani->eleCount; j++) {
        //     assert(ctx->ctx_UI->pn_towerMani != NULL);
        //     PlogNoArg("a\r\n");
        //     PN_TowerManiEle* ele = &ctx->ctx_UI->pn_towerMani->element[i];
        //     ele->isClick = PN_TowerManiEle_IsClick(ele, input->mouseWorldPos, input->isMouseDown);
        //     if (ele->isClick) {
        //         cell->isCellToTower = true;
        //         D_UI_Tower_Close(ctx);
        //         PlogNoArg("isCellToTower\r\n");
        //     }
        // }
    }
}

void B_Game_Draw(Ctx* ctx) {
    // Draw cell
    int cellLenth = ctx->rp_Cell->count;
    for (int i = 0; i < cellLenth; i++) {
        E_cell* cell = ctx->rp_Cell->all[i];
        E_cell_Draw(cell);
    }

    // Draw Mst
    int mstLenth = ctx->rp_mst->count;
    for (int i = 0; i < mstLenth; i++) {
        E_Mst* mst = ctx->rp_mst->all[i];
        if (mst->isLive) {
            E_Mst_Draw(mst);
        }
    }
}

#endif