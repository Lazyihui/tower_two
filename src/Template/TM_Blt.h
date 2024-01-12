#ifndef TEMPLATE_TM_BLT_H__
#define TEMPLATE_TM_BLT_H__

#include "import.h"

typedef struct TM_Blt {
    Color color;
    int typeID;
    float radius;
    float speed;
    float hurtRange;

} TM_Blt;

TM_Blt TM_Blt_Create(Color color, float radius, float speed, float hurtRange,int typeID) {
    TM_Blt tm;
    tm.color = color;
    tm.speed = speed;
    tm.radius = radius;
    tm.hurtRange = hurtRange;
    tm.typeID=typeID;
    return tm;
}

#endif