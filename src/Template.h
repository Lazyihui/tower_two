#ifndef TEMPLATE_H__
#define TEMPLATE_H__

#include <stdio.h>
#include <stdlib.h>
#include "Common.h"
#include "E_cell.h"

typedef struct Template
{
    TM_Cell *cells;
    int cellLenth;
    /* data */
}Template;


void Template_Init(Template *tpl) {

    tpl->cellLenth = 0;
    tpl->cells = (TM_Cell *)malloc(sizeof(TM_Cell) * 50);

    TM_Cell *cell = tpl->cells;
    TM_Cell c1;
    c1.typeID = 1;
    c1.shapeType = SHAPE_TYPE_RECT;
    c1.color = BLUE;
    c1.size.x =std_towerCell;
    c1.size.y=std_towerCell;

    cell[tpl->cellLenth++] = c1;
}


void Template_free(Template *tpl){
    free(tpl->cells);
    free(tpl);
}

TM_Cell *Template_GetCell(Template *tpl,int typeID){
    for(int i=0;i<tpl->cellLenth;i++){
        if(tpl->cells[i].typeID=typeID){
            return &tpl->cells[i];
        }
    }
    return NULL;
}

#endif