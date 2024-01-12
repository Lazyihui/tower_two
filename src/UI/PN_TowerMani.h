#ifndef UI_PNTOWERMANIFEST_H__
#define UI_PNTOWERMANIFEST_H__

#include "import.h"
#include "PN_TowerManiEle.h"

typedef struct PN_TowerMani {
    Vector2 startPos;
    float gapY;
    PN_TowerManiEle element[100];
    int eleCount;
    int clickedCellID;
    bool isOpen;
    bool isClickEle;
    void (*onClickStartHandle)(void);
} PN_TowerMani;

void PN_TowerMani_Ctor(PN_TowerMani* panel, void (*onClickStartHandle)(void)) {
    panel->gapY = std_cell / 4;
    panel->onClickStartHandle = onClickStartHandle;
}

void PN_TowerMani_Init(PN_TowerMani* panel, Vector2 pos, int cellID) {
    panel->startPos = pos;
    panel->eleCount = 0;
    panel->isOpen = true;
    panel->isClickEle = false;
    panel->clickedCellID = cellID;
}

void PanelTower_AddEle(PN_TowerMani* panel, int typeID, Color color) {
    int count = panel->eleCount;
    PN_TowerManiEle ele = PN_TowerManiEle_Init(count, typeID, color);
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

bool PanelTower_Isclick(PN_TowerMani* panel, Vector2 mouseWorldPos, bool isMouseDown, int* outTowerTypeID) {
    for (int i = 0; i < panel->eleCount; i++) {
        PN_TowerManiEle* ele = &panel->element[i];
        if (PN_TowerManiEle_IsClick(ele, mouseWorldPos, isMouseDown)) {
            *outTowerTypeID = ele->typeID;
            return true;
        }
    }
    return false;
}
void PanelTower_Close(PN_TowerMani* panel) {
    panel->eleCount = 0;
    panel->isOpen = false;
    panel->isClickEle = false;
}

void PanelTower_Draw(PN_TowerMani* panel) {
    assert(panel != NULL);
    if (!panel->isOpen) {
        return;
    } else {
        Vector2 startPos = panel->startPos;
        DrawRectangleV(Vector2_New(startPos.x - 1, startPos.y - 1),
                       Vector2_New(std_cell + 2, panel->eleCount * std_cell + 7), BLACK);

        for (int i = 0; i < panel->eleCount; i++) {
            PN_TowerManiEle* ele = &panel->element[i];
            Rectangle eleRect = RectangleNew(startPos.x, startPos.y + (panel->gapY + std_cell) * i, std_cell, std_cell);
            ele->rect = eleRect;
            PN_TowerManiEle_Draw(ele);
            // printf("PanelTower_Draw\r\n");
        }
    }
}

#endif