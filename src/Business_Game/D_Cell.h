#ifndef BUSINESS_D_CELL_H__
#define BUSINESS_D_CELL_H__

#include "import.h"

void D_Cell_Spawn(Ctx* ctx, int typeID, Vector2 pos) {

    E_cell* cell = Factory_Create_Cell(ctx, typeID, pos);
    if (cell != NULL) {
        RP_Cell_Add(ctx->rp_Cell, cell);
    }
}

void D_Cell_ToTower(Ctx* ctx) {
    for (int i = 0; i < ctx->rp_Cell->count; i++) {
        E_cell* cell = ctx->rp_Cell->all[i];
        assert(cell != NULL);
        cell->isClick = E_cell_IsMouseInsideClick(cell, ctx->input->mouseWorldPos, ctx->input->isMouseDown);
        
        if (cell->isClick) {

            cell->isCellToTower = true;
            
        }
    }
}

#endif