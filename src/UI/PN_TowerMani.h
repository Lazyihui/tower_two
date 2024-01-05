#ifndef UI_PNTOWERMANIFEST_H__
#define UI_PNTOWERMANIFEST_H__

#include "import.h"
#include "PN_TowerManiEle.h"

typedef struct PN_TowerMani {
    Vector2 startPos;
    float gapY;
    PN_TowerManiEle element[100];
    int eleCount;
    bool isOpen;
    void (*onClickStartHandle)(void);
} PN_TowerMani;

void PN_TowerMani_Ctor(PN_TowerMani* panel, void (*onClickStartHandle)(void)) {
    panel->gapY = std_cell / 4;
    panel->onClickStartHandle = onClickStartHandle;
}

void PN_TowerMani_Init(PN_TowerMani* panel, Vector2 pos) {
    panel->startPos = pos;
    panel->eleCount = 0;
    panel->isOpen = true;
}

void PanelTower_AddEle(PN_TowerMani* panel, int typeID, Color color) {
    int count = panel->eleCount;
    PN_TowerManiEle ele = PN_TowerManiEle_Create(count, typeID, color);
    panel->element[count++] = ele;
    panel->eleCount = count;
}

int PanelTower_Click(PN_TowerMani* panel, Vector2 mouseWorldPos, bool isMouseDown) {
    for (int i = 0; i < panel->eleCount; i++) {
        PN_TowerManiEle* ele = &panel->element[i];
        if (PN_TowerManiEle_IsClick(ele, mouseWorldPos, isMouseDown)) {
            return ele->typeID;
        }
    }
    return -1;
}

void PanelTower_Close(PN_TowerMani* panel) {
    panel->eleCount = 0;
    panel->isOpen = false;
}

void PanelTower_Draw(PN_TowerMani* panel) {
    assert(panel != NULL);
    if (!panel->isOpen) {
        return;
    } else {
        Vector2 startPos = panel->startPos;
        DrawRectangleV(startPos, Vector2_New(std_cell + 4, panel->eleCount * std_cell + 4), BLACK);
        for (int i = 0; i < panel->eleCount; i++) {
            PN_TowerManiEle* ele = &panel->element[i];
            Rectangle eleRect = RectangleNew(startPos.x, startPos.y + (panel->gapY + std_cell) * i , std_cell, std_cell);
            ele->rect = eleRect;
            PN_TowerManiEle_Draw(ele);
            // printf("PanelTower_Draw\r\n");
        }
    }
}

#endif