
#include "Ctx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/raylib.h"
#include "../include/raymath.h"

int main() {

    // 16:9
    InitWindow(960, 540, "Draw");
    Ctx* ctx = (Ctx*)calloc(1, sizeof(Ctx));
    SetTargetFPS(60);
    //==== Enter ====
    ctx_Inti(ctx);
    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();

        BeginMode2D(ctx->cam.camera);

        ClearBackground(RAYWHITE);

        //==== Input ====

        //==== Logic Tick ====

        //==== Draw World ====
        DrawCircle(0, 0, 100, RED);

        EndMode2D();
        // ==== Draw UI ====

        EndDrawing();
    }
    CloseWindow();
    ctx_Free(ctx);
    return 0;
}