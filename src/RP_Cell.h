#ifndef RP_CELL_H__
#define RP_CELL_H__

#include <stdio.h>
#include "E_cell.h"


typedef struct RP_Cell {
    E_cell **all;
    int count;
} RP_Cell;


void RP_Cell_Init(RP_Cell *rp) {
    rp->all = (E_cell **)calloc(40 * 23 * 10, sizeof(E_cell *));
    printf("%d", sizeof(E_cell *));
    rp->count = 0;
}

#endif