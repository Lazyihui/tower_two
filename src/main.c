#include <stdio.h>
#include <stdlib.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
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
    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();

        BeginMode2D(ctx->cam.camera);

        ClearBackground(RAYWHITE);

        //==== Input ====
if(APP_UI_Login_IsStartClick(ctx->ctx_UI)){
    APP_UI_Login_Close(ctx->ctx_UI);
}
        //==== Logic Tick ====

        //==== Draw World ====
        // DrawCircle(0, 0, 100, RED);

        EndMode2D();
        // ==== Draw UI ====
        APP_UI_Draw(ctx->ctx_UI);
        
        EndDrawing();
    }
    CloseWindow();
    ctx_Free(ctx);
    return 0;
}