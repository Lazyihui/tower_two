#ifndef TEMPLATE_H__
#define TEMPLATE_H__

#include <stdio.h>
#include <stdlib.h>
#include "Common.h"
#include "E_cell.h"
#include "E_Mst.h"

typedef struct Template
{
    //cell
    TM_Cell *cells;
    int cellLenth;

//mst
    TM_Mst *msts;
    int mstLenth;

}Template;


void Template_Cell_Init(Template *tpl) {

    tpl->cellLenth = 0;
    tpl->cells = (TM_Cell *)malloc(sizeof(TM_Cell) * 20);

    TM_Cell *cell = tpl->cells;
    TM_Cell c1;
    c1.typeID = 1;
    c1.shapeType = SHAPE_TYPE_RECT;
    c1.color = BLUE;
    c1.size.x =std_towerCell;
    c1.size.y=std_towerCell;

    cell[tpl->cellLenth++] = c1;
}

void Template_Mst_Init(Template *tpl){
    tpl->mstLenth=0;
    tpl->msts=(TM_Mst*)calloc(1000,sizeof(TM_Mst));

    TM_Mst *mst = tpl->msts;
    TM_Mst mst_small;
    mst_small.typeID = 1;
    mst_small.speed = 20;
    mst_small.radius = 10;
    mst_small.color = RED;
    mst_small.hp = 1;
    mst[tpl->mstLenth++]=mst_small;


    TM_Mst mst_max;
    mst_max.typeID = 2;
    mst_max.speed = 30;
    mst_max.radius = 20;
    mst_max.color = GRAY;
    mst_max.hp = 2;
    mst[tpl->mstLenth++]=mst_max;

}

void Template_free(Template *tpl){
    free(tpl->cells);
    free(tpl->msts);
    free(tpl);
}

TM_Cell *Template_GetCell(Template *tpl,int typeID){
    for(int i=0;i<tpl->cellLenth;i++){
        if(tpl->cells[i].typeID==typeID){
            return &tpl->cells[i];
        }
    }
    return NULL;
}

TM_Mst *Template_GetMst(Template *tpl,int typeID){
    for(int i=0;i<tpl->mstLenth;i++){
        if(tpl->msts[i].typeID==typeID){
            return &tpl->msts[i];
        }
    }

    return NULL;
    
}

#endif