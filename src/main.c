#define RAYGUI_IMPLEMENTATION

#include "Business_Game/export.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static Ctx* ctx; // 静态区

// 文本区
void UI_Login_OnClicckStart() {
    APP_UI_Login_Close(ctx->ctx_UI);
    ctx->gameStatus = GAME_STATUS_GAME;
    B_Game_Enter(ctx);
}



int main() {
    ctx = (Ctx*)calloc(1, sizeof(Ctx));
    // 16:9
    InitWindow(960, 540, "Draw");
    PlogNoArg("GameStart");
    // 断言
    assert(ctx != NULL);
    SetTargetFPS(60);
    //==== Enter ====
    ctx_Inti(ctx);
    ctxUIInit(ctx->ctx_UI);
    APP_UI_Login_Open(ctx->ctx_UI, &UI_Login_OnClicckStart);

    int towerTypes[3] = {1, 2, 3};
    GuiLoadStyleCandy();
    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();

        BeginMode2D(ctx->cam.camera);

        ClearBackground(RAYWHITE);

        //==== Input ====
        // if (APP_UI_Login_Click(ctx->ctx_UI)) {
        E_Input_Process(ctx->input, Vector2_New(ctx->windowWidth / 2, ctx->windowheight / 2));

        // }
        //==== Logic Tick ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {
        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
            APP_UI_Game_Tick(ctx->ctx_UI, dt);
            B_Game_Tick(ctx, dt);
            // 格子和鼠标的交叉检测，得到格子的ID
            
        }
        //==== Draw World ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {

        } else if (ctx->gameStatus == GAME_STATUS_GAME) {

            APP_UI_Game_DrawWorld(ctx->ctx_UI);
            B_Game_Draw(ctx);
        }

        EndMode2D();
        // ==== Draw UI ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {
            APP_UI_Login_DrawUI(ctx->ctx_UI);

        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
            APP_UI_Game_Draw(ctx->ctx_UI);
        }

        EndDrawing();
    }
    CloseWindow();
    ctx_Free(ctx);
    return 0;
}