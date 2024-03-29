#ifndef PNTOWERMANIELE_H__
#define PNTOWERMANIELE_H__

#include "import.h"

typedef struct PN_TowerManiEle {
    int typeID;
    int index;
    Rectangle rect;
    Color color;
    bool isClick;
} PN_TowerManiEle;

PN_TowerManiEle PN_TowerManiEle_Init(int index, int typeID, Color color) {

    PN_TowerManiEle ele = (PN_TowerManiEle){0};
    ele.index = index;
    ele.typeID = typeID;
    ele.color = color;
    return ele;
}

bool PN_TowerManiEle_IsClick(PN_TowerManiEle* ele, Vector2 mouseWroldPos, bool isMouseDown) {
    

    if (IsMouseInsiderectRec(ele->rect, mouseWroldPos) && isMouseDown) {
        return true;
    } else {
        return false;
    }
}

void PN_TowerManiEle_Draw(PN_TowerManiEle* ele) {
    DrawRectangleRec(ele->rect, ele->color);
}
#endif