#ifndef D_CELL_H__
#define D_CELL_H__

#include "Ctx.h"
#include "Factory.h"
#include "E_cell.h"


void D_Cell_Spawn(Ctx *ctx,int typeID,Vector2 pos){

    E_cell *cell = Factory_Create_Cell(ctx,typeID,pos);

    
}

#endif