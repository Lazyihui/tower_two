#ifndef  BUSINESS_D_CELL_H__
#define  BUSINESS_D_CELL_H__

#include "import.h"

void D_Cell_Spawn(Ctx* ctx, int typeID, Vector2 pos) {

    E_cell* cell = Factory_Create_Cell(ctx, typeID, pos);
    if (cell != NULL) {
        RP_Cell_Add(ctx->rp_Cell, cell);
    }
}

#endif