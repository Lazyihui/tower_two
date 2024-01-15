#ifndef E_BULLET_H__
#define E_BULLET_H__

#include "import.h"

typedef struct E_Blt {
    int typeID;
    int ID;
    Color color;
    Vector2 pos;
    Vector2 moveAxis;
    float radius;
    float speed;
    float hurtRange;
    int hurt;
    bool isLive;
    bool isInside;
} E_Blt;

// 向敌人移动moveAxis
void E_Blt_InputByTarget(E_Blt* blt, Vector2 tarGetPos) {

    blt->moveAxis = Vector2Subtract(tarGetPos, blt->pos);
}

// blt pos
void E_Blt_Move(E_Blt* blt, Vector2 moveAxis, float dt) {
    Vector2 offest = Vector2Normalize(moveAxis);
    offest = Vector2Scale(offest, blt->speed * dt);
    blt->pos = Vector2Add(blt->pos, offest);
}

void E_Blt_Close(E_Blt* blt) {
    blt->isLive = false;
}

void E_Blt_Draw(E_Blt* blt) {
    DrawCircle(blt->pos.x, blt->pos.y, blt->radius, blt->color);
}

#endif