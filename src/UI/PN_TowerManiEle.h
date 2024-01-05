#ifndef PNTOWERMANIELE_H__
#define PNTOWERMANIELE_H__

#include "import.h"

typedef struct PN_TowerManiEle {
    int typeID;
    int index;
    Rectangle rect;
    Color color;
} PN_TowerManiEle;

PN_TowerManiEle PN_TowerManiEle_Init(int index, int typeID, Vector2 pos, Vector2 size) {

    PN_TowerManiEle ele = (PN_TowerManiEle){0};
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

bool PN_TowerManiEle_IsClick(PN_TowerManiEle* ele, Vector2 mouseWroldPos, bool isMouseDown) {

    if (IsRectInsideMouseRec) {
        return true;
    } else {
        return false;
    }
}

void PN_TowerManiEle_Draw(PN_TowerManiEle* ele) {
    DrawRectangleRec(ele->rect, ele->color);
}
#endif