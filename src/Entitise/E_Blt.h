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
    bool isLive;
    bool isInside;
} E_Blt;

void E_Bullet_Draw(E_Blt* blt) {
    DrawCircle(blt->pos.x, blt->pos.y, blt->radius, blt->color);
}

#endif