#ifndef E_MST_H__
#define E_MST_H__

#include "import.h"


typedef struct E_Mst {
    int ID;
    int typeID; // 1 Small, 2 Middle, 3 Big
    Color color;
    float radius;
    float speed;
    int hp;

    Vector2 pos;
    Vector2 moveAxis;
    bool isLive;

} E_Mst;


void E_Mst_Move(E_Mst* mst, Vector2 moveAxis, float dt) {
    Vector2* posptr = &mst->pos;
    Vector2 offset = Vector2Normalize(moveAxis);
    offset = Vector2Scale(offset, mst->speed * dt);
    *posptr = Vector2Add(*posptr, offset);
}

void E_Mst_Draw(E_Mst* mst) {
    DrawCircle(mst->pos.x, mst->pos.y, mst->radius, mst->color);
}
#endif