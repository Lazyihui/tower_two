#ifndef FACTORY_H__
#define FACTORY_H__

#include "Ctx.h"
#include "E_cell.h"
#include "Template.h"
#include "S_ID.h"
#include "E_Mst.h"

E_cell* Factory_Create_Cell(Ctx* ctx, int typeID, Vector2 pos) {

    TM_Cell* tm = Template_GetCell(ctx->tpl, typeID);
    if (tm == NULL) {
        printf("err : Template_GetCell() return NULL\n");
        return NULL;
    }

    E_cell* cell = (E_cell*)malloc(sizeof(E_cell));
    cell->ID = ctx->s_id->cellIDRecord++;
    cell->typeID = typeID;
    cell->pos = pos;
    cell->shapeType = tm->shapeType;
    cell->size = tm->size;
    cell->color = tm->color;

    return cell;
}

E_Mst* Factory_Create_Mst(Ctx* ctx, int typeID, Vector2 pos, Vector2 moveAxis) {
    TM_Mst* tm = Template_GetMst(ctx->tpl, typeID);
    if (tm == NULL) {
        printf("err : Factory_Create_Mst() return NULL\n");
        return NULL;
    }
    E_Mst* mst = (E_Mst*)calloc(1, sizeof(E_Mst));
    mst->ID = ctx->s_id->mstIDRecord++;
    mst->pos = pos;
    mst->hp = tm->hp;
    mst->color = tm->color;
    mst->radius = tm->radius;
    mst->speed = tm->speed;
    mst->moveAxis = moveAxis;
    mst->isLive=false;


    return mst;
}

#endif