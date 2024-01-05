#ifndef UI_PNTOWERMANIFEST_H__
#define UI_PNTOWERMANIFEST_H__

#include "import.h"

typedef struct UI_PanelEle {
    int typeID;
    int index;
    Rectangle rect;
    Color color;
} UI_PanelEle;

UI_PanelEle UI_PanelEle_CreatTowerType(int index, int typeID, Vector2 pos, Vector2 size) {

    UI_PanelEle ele = (UI_PanelEle){0};
    ele.index = index;
    ele.index = typeID;
    Color color;
    switch (typeID) {
    case 1: color = RED; break;
    case 2: color = YELLOW; break;
    case 3: color = GREEN; break;

    default:
        color = BLACK;
        printf("err UI_PanelEle_CreatTowerType\r\n");
        // Plog("ERR");
        break;
    }
    ele.rect.height = size.y;
    ele.rect.width = size.x;
    ele.rect.x = pos.x;
    ele.rect.y = pos.y;
    ele.color = color;
    return ele;
}

bool UI_PanelEle_IsClick(UI_PanelEle* ele, Vector2 mouseWroldPos, bool isMouseDown) {

    if (IsRectInsideMouseRec) {
        return true;
    } else {
        return false;
    }
}

void UI_PanelEle_Draw(UI_PanelEle* ele) {
    DrawRectangleRec(ele->rect, ele->color);
}

typedef struct PanelTower {
    Vector2 startPos;
    float gapY;
    int eleSize;
    // UI_PanelEle *element;
    UI_PanelEle element[3];
    int eleCount;
    bool isOpen;
    void (*onClickStartHandle)(void);
} PanelTower;

void PanelTower_Spawn(PanelTower* panel) {
    panel->startPos.x = 0;
    panel->startPos.y = 0;
    panel->eleCount = 0;
    panel->eleSize = std_cell;
    panel->gapY = std_cell / 4;
    panel->isOpen = true;
}

void PanelTower_AddEle(PanelTower* panel, Vector2 worldPos, int typeID) {
    panel->startPos = worldPos;
    int count = panel->eleCount;
    Vector2 pos = Vector2Add(worldPos, Vector2_New(0, panel->gapY * count + panel->eleSize * count));
    UI_PanelEle ele = UI_PanelEle_CreatTowerType(count, typeID, pos, Vector2_New(panel->eleSize, panel->eleSize));
    panel->element[count++] = ele;
    // panel->element[count]=ele;
}

int PanelTower_Click(PanelTower* panel, Vector2 mouseWorldPos, bool isMouseDown) {
    for (int i = 0; i < panel->eleCount; i++) {
        UI_PanelEle* ele = &panel->element[i];
        if (UI_PanelEle_IsClick(ele, mouseWorldPos, isMouseDown)) {
            return ele->typeID;
        }
    }
    return -1;
}

void PanelTower_Close(PanelTower* panel) {
    panel->eleCount = 0;
    panel->isOpen = false;
}

void PanelTower_Draw(PanelTower* panel) {
    assert(panel != NULL);
    if (!panel->isOpen) {
        return;
    } else {
        DrawRectangle(50, 50, 50, 50, RED);
        for (int i = 0; i < panel->eleCount; i++) {
            UI_PanelEle* ele = &panel->element[i];
            UI_PanelEle_Draw(ele);
            printf("PanelTower_Draw\r\n");
        }
    }
}

#endif