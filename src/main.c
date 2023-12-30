#define RAYGUI_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "../include/raygui.h"
#include "../include/style_candy.h"
#include "Ctx.h"
#include "APP_UI.h"

int main() {

    // 16:9
    InitWindow(960, 540, "Draw");
    Ctx* ctx = (Ctx*)calloc(1, sizeof(Ctx));
    SetTargetFPS(60);
    //==== Enter ====
    ctx_Inti(ctx);
    APP_UI_Login_Open(ctx->ctx_UI);
    GuiLoadStyleCandy();
    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();

        BeginMode2D(ctx->cam.camera);

        ClearBackground(RAYWHITE);

        //==== Input ====
        if (APP_UI_Login_IsStartClick(ctx->ctx_UI)) {
            APP_UI_Login_Close(ctx->ctx_UI);
            ctx->gameStatus = GAME_STATUS_GAME;
        }
        //==== Logic Tick ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {

        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
        }
        //==== Draw World ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {

        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
            // DrawCircle(0, 0, 100, RED);
        }

        EndMode2D();
        // ==== Draw UI ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {
            APP_UI_Draw(ctx->ctx_UI);

        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
        }

        EndDrawing();
    }
    CloseWindow();
    ctx_Free(ctx);
    return 0;
}