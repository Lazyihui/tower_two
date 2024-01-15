#ifndef ENTITISE_E_TOWER_H__
#define ENTITISE_E_TOWER_H__

#include "import.h"

typedef struct E_Tower {
    int ID;
    int typeID;
    Vector2 pos;
    Vector2 size;
    Color color;

    int hurtRange;
    bool isLive;
    float bltSpawnTimer;
    float bltSpawnInterval;
} E_Tower;

void E_Tower_Draw(E_Tower* tower) {
    DrawRectangleV(tower->pos, tower->size, tower->color);
}

#endif