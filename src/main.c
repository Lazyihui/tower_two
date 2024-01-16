#define RAYGUI_IMPLEMENTATION

#include "Business_Game/export.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static Ctx* ctx; // 静态区

// 文本区
void UI_Login_OnClicckStart() {
    APP_UI_Login_Close(ctx->ctx_UI);
    B_Game_Enter(ctx);
}

void UI_Over_OnClicckStart() {
    PlogNoArg("a\r\n");
    APP_UI_Over_Close(ctx->ctx_UI);
    B_Login_Enter(ctx, &UI_Login_OnClicckStart);
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

    B_Login_Enter(ctx, &UI_Login_OnClicckStart);

    int towerTypes[3] = {1, 2, 3};
    GuiLoadStyleCandy();

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();

        BeginMode2D(ctx->cam.camera);

        ClearBackground(RAYWHITE);

        //==== Input ====
        // if (APP_UI_Login_Click(ctx->ctx_UI)) {
        E_Input_Process(ctx->input, Vector2_New(ctx->windowWidth / 2,
                                                ctx->windowheight / 2));

        // }
        //==== Logic Tick ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {
        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
            D_Play_Tick(ctx, dt);
            B_Game_Tick(ctx, dt);

            if (ctx->valuePlay <= 0) {
                B_Over_Enter(ctx);
            }
        } else if (ctx->gameStatus == GAME_STATUS_OVER) {
            APP_UI_Over_Open(ctx->ctx_UI, &UI_Over_OnClicckStart);
        }
        //==== Draw World ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {

        } else if (ctx->gameStatus == GAME_STATUS_GAME) {

            APP_UI_Game_DrawWorld(ctx->ctx_UI);
            B_Game_Draw(ctx);
        } else if (ctx->gameStatus == GAME_STATUS_OVER) {
        }

        EndMode2D();
        // ==== Draw UI ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {
            // GuiSliderBar(a, " ", " ", &value, 0, 100);
            APP_UI_Login_DrawUI(ctx->ctx_UI);

        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
            APP_UI_Game_Draw(ctx->ctx_UI, ctx->valuePlay, ctx->time, ctx->gold);
        } else if (ctx->gameStatus == GAME_STATUS_OVER) {
            APP_UI_Over_DrawUI(ctx->ctx_UI);
        }

        EndDrawing();
    }
    CloseWindow();
    ctx_Free(ctx);
    return 0;
}