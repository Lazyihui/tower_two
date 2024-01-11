#ifndef E_CELL_H__
#define E_CELL_H__

#include "import.h"

typedef struct E_cell {

    int ID;
    int typeID;
    Vector2 pos;

    ShapeType shapeType;
    Color color;
    Vector2 size;

    bool isCellToTower;
    bool isClick;

} E_cell;

void E_cell_Draw(E_cell* cell) {
    Vector2 center = cell->pos;
    center = Vector2Subtract(center, Vector2Scale(cell->size, 0.5f));
    if (cell->shapeType == SHAPE_TYPE_CIRCLE) {
        DrawCircleV(center, cell->size.x / 2, cell->color);
    } else if (cell->shapeType == SHAPE_TYPE_RECT) {
        DrawRectangleV(cell->pos, cell->size, cell->color);
    } else {
        printf("E_cell_Draw err");
    }
}

bool E_cell_IsMouseInsideClick(E_cell* cell, Vector2 mouseWorldPos, bool isMouseDown) {

    cell->isClick = IsMouseInsideRect(cell->pos, cell->size.x, cell->size.x, mouseWorldPos);

    if (cell->isClick && isMouseDown) {
        return true;
    } else {

        return false;
    }
}

#endif