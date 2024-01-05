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

void UI_PanelTower() {
    // Plog("UI_PanelTower");
    printf("UI_PanelTower");
}

int main() {
    ctx = (Ctx*)calloc(1, sizeof(Ctx));
    // 16:9
    InitWindow(960, 540, "Draw");
    // 断言
    assert(ctx != NULL);
    SetTargetFPS(60);
    //==== Enter ====
    ctx_Inti(ctx);
    ctxUIInit(ctx->ctx_UI);
    APP_UI_Login_Open(ctx->ctx_UI, &UI_Login_OnClicckStart);
    APP_UI_PanelTower_Open(ctx->ctx_UI, Vector2_New(0, 2), &UI_PanelTower);
    // Plog("start Game %f\r\n", ctx->mstSpawnInterval);

    GuiLoadStyleCandy();
    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();

        BeginMode2D(ctx->cam.camera);

        ClearBackground(RAYWHITE);

        //==== Input ====
        // if (APP_UI_Login_Click(ctx->ctx_UI)) {

        // }
        //==== Logic Tick ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {
        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
            APP_UI_Game_Tick(ctx->ctx_UI, dt);
            B_Game_Tick(ctx, dt);
            assert(ctx->ctx_UI != NULL);
            if (IsKeyPressed(KEY_A)) {
                ctx->ctx_UI->PanelTower->isOpen = true;
                for (int i = 0; i < 3; i++) {

                    int typeID = ctx->ctx_UI->typeTower[i];
                    PanelTower_AddEle(ctx->ctx_UI->PanelTower, Vector2_New(50, 50), typeID);
                }
            } else {
                PanelTower_Close(ctx->ctx_UI->PanelTower);
            }
        }
        //==== Draw World ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {

        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
            // DrawCircle(0, 0, 100, RED);

            APP_UI_Game_DrawWorld(ctx->ctx_UI);
            B_Game_Draw(ctx);

            // DrawRectangle(0,26*std_cell,10,10,RED);
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