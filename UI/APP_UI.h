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

    ctxUI->rectWorldHp.height = 20;
    ctxUI->rectWorldHp.width = 130;
    ctxUI->rectWorldHp.x = 30;
    ctxUI->rectWorldHp.y = 60;
    ctxUI->value = 100;
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
    DrawText("time", 2 * std_cell, (int)1.5 * std_cell, 2 * std_cell, BLACK);
    Text_Int(ctxUI->time, (int)7 * std_cell, (int)1.5 * std_cell, 2 * std_cell, ORANGE);

    // gold
    DrawText("gold", 2 * std_cell, (int)3.5 * std_cell, 2 * std_cell, BLACK);
    Text_Int(ctxUI->gold, (int)7 * std_cell, (int)3.5 * std_cell, 2 * std_cell, ORANGE);

    // silder
    float value = ctxUI->value;
    GuiSliderBar(ctxUI->rectWorldHp, "hp", " ", &value, 0, 10 * std_cell);
}

void APP_UI_Game_DrawWorld(CtxUI* ctxUI) {
    // 路
    DrawRectangle(std_cell * -5, std_cell *(int) -26.5, std_cell * 10, std_cell * 53, BROWN);
}

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
