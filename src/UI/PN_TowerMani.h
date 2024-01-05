#ifndef UI_PNTOWERMANIFEST_H__
#define UI_PNTOWERMANIFEST_H__

#include "import.h"
#include "PN_TowerManiEle.h"

typedef struct PN_TowerMani {
    Vector2 startPos;
    float gapY;
    int eleSize;
    // UI_PanelEle *element;
    PN_TowerManiEle element[3];
    int eleCount;
    bool isOpen;
    void (*onClickStartHandle)(void);
} PN_TowerMani;

void PanelTower_Spawn(PN_TowerMani* panel) {
    panel->startPos.x = 0;
    panel->startPos.y = 0;
    panel->eleCount = 0;
    panel->eleSize = std_cell;
    panel->gapY = std_cell / 4;
    panel->isOpen = true;
}

void PanelTower_AddEle(PN_TowerMani* panel, Vector2 worldPos, int typeID) {
    panel->startPos = worldPos;
    int count = panel->eleCount;
    Vector2 pos = Vector2Add(worldPos, Vector2_New(0, panel->gapY * count + panel->eleSize * count));
    PN_TowerManiEle ele = PN_TowerManiEle_Init(count, typeID, pos, Vector2_New(panel->eleSize, panel->eleSize));
    panel->element[count++] = ele;
    // panel->element[count]=ele;
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
        DrawRectangle(50, 50, 50, 50, RED);
        for (int i = 0; i < panel->eleCount; i++) {
            PN_TowerManiEle* ele = &panel->element[i];
            PN_TowerManiEle_Draw(ele);
            printf("PanelTower_Draw\r\n");
        }
    }
}

#endif