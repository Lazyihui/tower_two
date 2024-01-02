#ifndef FACTORY_H__
#define FACTORY_H__

#include "Ctx.h"
#include "E_cell.h"
#include "Template.h"
#include "S_ID.h"

E_cell *Factory_Create_Cell(Ctx *ctx, int typeID, Vector2 pos) {

    TM_Cell *tm = Template_GetCell(ctx->tpl, typeID);
    if (tm == NULL) {
        printf("err : Template_GetCell() return NULL\n");
        return NULL;
    }

    E_cell *cell = (E_cell *)malloc(sizeof(E_cell));
    cell->ID = ctx->s_id->cellIDRecord++;
    cell->typeID = typeID;
    cell->pos = pos;
    cell->shapeType = tm->shapeType;
    cell->size = tm->size;
    cell->color = tm->color;

    return cell;
}


#endif