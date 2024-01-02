#ifndef B_GAME_H__
#define B_GAME_H__

#include "E_cell.h"
#include "D_Cell.h"
#include "Ctx.h"

void B_Game_Tick(Ctx* ctx) {
}

void B_Game_Draw(Ctx* ctx) {

    int cellLenth = ctx->rp_Cell->count;
    for (int i = 0; i < cellLenth; i++) {
        E_cell* cell = ctx->rp_Cell->all[i];
        E_cell_Draw(cell);
    }
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
#endif