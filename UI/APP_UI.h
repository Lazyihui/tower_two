#ifndef APP_UI_H__
#define APP_UI_H__

#include "PN_Login.h"
#include "../src/Common.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct CtxUI {
    PN_Login* pn_login;
    float time;
    float gold;

    // slider
    Rectangle rectWorldHp;
    float value;
} CtxUI;

void ctxUIInit(CtxUI* ctxUI) {
    ctxUI->time = 0;
    ctxUI->gold = 0;

    ctxUI->rectWorldHp.height = 30;
    ctxUI->rectWorldHp.width = 60;
    ctxUI->rectWorldHp.x = 20;
    ctxUI->rectWorldHp.y = 60;
    ctxUI->value = 90;
}

// 释放
void APP_UI_Free(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        free(ctxUI->pn_login);
        ctxUI->pn_login = NULL;
    }
    free(ctxUI);
}

// 画
void APP_UI_Login_DrawUI(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        PN_Login_Draw(ctxUI->pn_login);
    }
}

// 画时间 金钱
void APP_UI_Game_Draw(CtxUI* ctxUI) {
    // time
    DrawText("time", 20, 15, 20, BLACK);
    Text_Int(ctxUI->time, 63, 15, 20, ORANGE);

    // gold
    DrawText("gold", 20, 35, 20, BLACK);
    Text_Int(ctxUI->gold, 63, 35, 20, ORANGE);

    // silder
    float value =ctxUI->value;
    GuiSliderBar(ctxUI->rectWorldHp, "hp", "t", &value, 0, 100);
}




// void B_Game_DrawScreenUI(Ctx* ctx) {

//     // 时间
//     DrawText("time", 20, 15, 20, BLACK);
//     Text_Int(ctx->time, 63, 15, 20, ORANGE);

//     // 金钱
//     DrawText("gold", 20, 35, 20, BLACK);
//     Text_Int(ctx->gold, 63, 35, 20, ORANGE);

//     // 血量slider
//     DrawRectangle(20, 60, 100, 15, RED);
//     DrawRectangle(20, 60, ctx->hp, 15, GREEN);

//     // 要改的
//     if (IsKeyPressed(KEY_SPACE)) {
//         ctx->hp -= 10;
//     }
// }
// panel 使panel存在
void APP_UI_Login_Open(CtxUI* ctxUI, void (*onClickStartHandle)(void)) {
    PN_Login* panel = (PN_Login*)calloc(1, sizeof(PN_Login));
    // 这里存在了
    panel->onClickStartHandle = onClickStartHandle;
    PN_Login_Spawn(panel);
    ctxUI->pn_login = panel;
}

// 关闭panel
void APP_UI_Login_Close(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        free(ctxUI->pn_login);
        ctxUI->pn_login = NULL;
    }
}

bool APP_UI_Login_Click(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        return ctxUI->pn_login->isClick;
    }
    return false;
}

void APP_UI_Game_Tick(CtxUI* ctxUI, float dt) {
    ctxUI->time += dt;
    ctxUI->gold += dt * 2.0f;
}

#endif
