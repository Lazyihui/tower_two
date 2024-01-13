#ifndef FACTORY_H__
#define FACTORY_H__

#include "Ctx.h"

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
    cell->isCellToTower = false;
    cell->isClick = false;

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
    mst->hpMax = tm->hp;
    mst->color = tm->color;
    mst->radius = tm->radius;
    mst->speed = tm->speed;
    mst->moveAxis = moveAxis;
    mst->isLive = true;
    mst->isInside = false;
    return mst;
}

E_Tower* Factory_Create_Tower(Ctx* ctx, int typeID, Vector2 pos) {
    TM_Tower* tm = Template_GetTower(ctx->tpl, typeID);
    if (tm == NULL) {
        PlogNoArg("return NUll");
        return NULL;
    }
    E_Tower* tower = (E_Tower*)calloc(1, sizeof(E_Tower));
    tower->ID = ctx->s_id->towerRecord++;
    tower->color = tm->worldColor;
    tower->hurt = tm->hurt;
    tower->typeID = tm->typeID;
    tower->pos = pos;
    tower->size = tm->size;
    tower->isLive = false;
    tower->bltSpawnInterval = 2;
    tower->bltSpawnTimer = 2;
    return tower;
}

E_Blt* Factory_Create_Blt(Ctx* ctx, int typeID, Vector2 moveAxis, Vector2 pos) {
    TM_Blt* tm = Template_GetBlt(ctx->tpl, typeID);
    if (tm == NULL) {
        PlogNoArg("return NUll");
        return NULL;
    }
    E_Blt* blt = (E_Blt*)calloc(1, sizeof(E_Blt));
    blt->ID = ctx->s_id->bltRecord++;
    blt->color = tm->color;
    blt->hurtRange = tm->hurtRange;
    blt->moveAxis = moveAxis;
    blt->isInside = false;
    blt->isLive = false;
    blt->pos = pos;
    blt->radius = tm->radius;
    blt->speed = tm->speed;
    blt->typeID = tm->typeID;
    return blt;
}

#endif