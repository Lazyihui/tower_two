#ifndef TM_CELL_H__
#define TM_CELL_H__

#include "import.h"

typedef struct TM_Cell
{   
    int typeID;
    ShapeType shapeType;
    Color color;
    Vector2 size;
    /* data */
}TM_Cell;



#endif