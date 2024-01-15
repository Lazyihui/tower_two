#ifndef APP_UI_H__
#define APP_UI_H__

#include "PN_Login.h"
#include <stdio.h>
#include <stdlib.h>
#include "PN_TowerMani.h"
#include "PN_Over.h"

typedef struct CtxUI {
    PN_Login* pn_login;

    PN_Over* pn_over;
    // slider
    Rectangle rectWorldHp;
    float value;

    PN_TowerMani* pn_towerMani;
    int typeTower[3];

    Rectangle mstHp;
    float mstvalue;

} CtxUI;

void ctxUIInit(CtxUI* ctxUI) {

    ctxUI->rectWorldHp.height = 20;
    ctxUI->rectWorldHp.width = 130;
    ctxUI->rectWorldHp.x = 30;
    ctxUI->rectWorldHp.y = 60;
    ctxUI->mstvalue = 100;

    for (int i = 0; i < 3; i++) {
        ctxUI->typeTower[i] = i + 1;
    }

    ctxUI->mstHp.height = 10;
    ctxUI->mstHp.width = 100;
    ctxUI->value = 100;
}

bool APP_UI_PanelTowerIsClick(CtxUI* ctxUI, Vector2 mouseWorldPos,
                              bool isMouseDown, int* outCellID,
                              int* outTowerTypeID) {
    PN_TowerMani* panel = ctxUI->pn_towerMani;
    if (panel != NULL) {
        *outCellID = panel->clickedCellID;
        return PanelTower_Isclick(panel, mouseWorldPos, isMouseDown,
                                  outTowerTypeID);
    } else {
        return false;
    }
}

// 释放
void APP_UI_Free(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        free(ctxUI->pn_login);
        ctxUI->pn_login = NULL;
    }
    if (ctxUI->pn_over != NULL) {
        free(ctxUI->pn_over);
        ctxUI->pn_over = NULL;
    }
    free(ctxUI);
}

// 画
void APP_UI_Login_DrawUI(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        PN_Login_Draw(ctxUI->pn_login);
    }
}

void APP_UI_Over_DrawUI(CtxUI* ctxUI) {
    if (ctxUI->pn_over != NULL) {
        PN_Over_Draw(ctxUI->pn_over);
    }
}

// 画时间 金钱
void APP_UI_Game_Draw(CtxUI* ctxUI, float valuePlay, float time, float gold) {
    // time
    DrawText("time", 2 * std_cell, (int)1.5 * std_cell, 2 * std_cell, BLACK);
    Text_Int(time, (int)7 * std_cell, (int)1.5 * std_cell, 2 * std_cell,
             ORANGE);

    // gold
    DrawText("gold", 2 * std_cell, (int)3.5 * std_cell, 2 * std_cell, BLACK);
    Text_Int(gold, (int)7 * std_cell, (int)3.5 * std_cell, 2 * std_cell,
             ORANGE);

    // silder
    float value = valuePlay;
    GuiSliderBar(ctxUI->rectWorldHp, "hp", " ", &value, 0, 10);

    DrawRectangle((int)2 * std_cell, (int)9.5 * std_cell, std_cell * 2,
                  std_cell * 2, RED);
    DrawRectangle((int)2 * std_cell, (int)11.5 * std_cell, std_cell * 2,
                  std_cell * 2, GREEN);
    DrawRectangle((int)2 * std_cell, (int)13.5 * std_cell, std_cell * 2,
                  std_cell * 2, YELLOW);
    DrawText("10 gold", (int)6 * std_cell, (int)9.5 * std_cell, std_cell * 2,
             BLACK);
    DrawText("20 gold", (int)6 * std_cell, (int)11.5 * std_cell, std_cell * 2,
             BLACK);
    DrawText("30 gold", (int)6 * std_cell, (int)13.5 * std_cell, std_cell * 2,
             BLACK);
}

void APP_UI_Game_DrawWorld(CtxUI* ctxUI) {
    // 路
    DrawRectangle(std_cell * -5, std_cell * (int)-26.5, std_cell * 10,
                  std_cell * 53, BROWN);
    // panel tower
    if (ctxUI->pn_towerMani != NULL) {
        PanelTower_Draw(ctxUI->pn_towerMani);
    }
}

void APP_UI_PanelTower_Open(CtxUI* ctxUI, Vector2 pos, int cellID,
                            void (*onClickStartHandle)(void)) {
    PN_TowerMani* panel = ctxUI->pn_towerMani;
    if (panel == NULL) {
        panel = (PN_TowerMani*)calloc(1, sizeof(PN_TowerMani));
        PN_TowerMani_Ctor(panel, onClickStartHandle);
        ctxUI->pn_towerMani = panel;
    }
    PN_TowerMani_Init(panel, pos, cellID);
}

void APP_UI_PanelTower_Close(CtxUI* ctxUI) {
    PanelTower_Close(ctxUI->pn_towerMani);
}

bool APP_UI_PanelTower_IsOpen(CtxUI* ctxUI) {
    PN_TowerMani* panel = ctxUI->pn_towerMani;

    if (panel == NULL) {
        return false;
    }
    return panel->isOpen;
}

void APP_UI_PanelTower_Add(CtxUI* ctxUI, int typeID, Color color) {
    PanelTower_AddEle(ctxUI->pn_towerMani, typeID, color);
}

// panel 使panel存在
void APP_UI_Login_Open(CtxUI* ctxUI, void (*onClickStartHandle)(void)) {
    PN_Login* panel = (PN_Login*)calloc(1, sizeof(PN_Login));
    // 这里存在了
    panel->onClickStartHandle = onClickStartHandle;
    PN_Login_Spawn(panel);
    ctxUI->pn_login = panel;
}

void APP_UI_Over_Open(CtxUI* ctxUI, void (*onClickStartHandle)(void)) {
    PN_Over* panel = (PN_Over*)calloc(1, sizeof(PN_Over));
    panel->onClickStartHandle = onClickStartHandle;
    PN_Over_Spawn(panel);
    PlogNoArg("a\r\n");

    ctxUI->pn_over = panel;
}

// 关闭panel
void APP_UI_Login_Close(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        free(ctxUI->pn_login);
        ctxUI->pn_login = NULL;
    }
}

void APP_UI_Over_Close(CtxUI* ctxUI) {
    if (ctxUI->pn_over != NULL) {
        free(ctxUI->pn_login);
        ctxUI->pn_over = NULL;
    }
}

bool APP_UI_Over_Click(CtxUI* ctxUI) {
    if (ctxUI->pn_over != NULL) {
        return ctxUI->pn_over->isClick;
    }
    return false;
}

bool APP_UI_Login_Click(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        return ctxUI->pn_login->isClick;
    }
    return false;
}

#endif
