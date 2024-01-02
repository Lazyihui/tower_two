#ifndef CTX_H__
#define CTX_H__

#include <stdio.h>
#include <stdlib.h>
#include "../include/raylib.h"
#include "Common.h"
#include "../UI/APP_UI.h"
#include "E_Camera.h"
#include "Template.h"
#include "S_ID.h"
#include "RP_Cell.h"

typedef struct Ctx {

    int windowWidth;
    int windowheight;

    int gameStatus;
    // Camera
    E_Camera cam;

    // UI
    CtxUI* ctx_UI;

    // panel
    PN_Login* pn_Login;

    // tpl
    Template* tpl;

    // id
    S_ID* s_id;

    //RP
    RP_Cell *rp_Cell;

} Ctx;

void ctx_Inti(Ctx* ctx) {

    ctx->windowWidth = 960;
    ctx->windowheight = 540;

    ctx->gameStatus = GAME_STATUS_LOGIN;

    // camera
    CameraEntity_Init(&ctx->cam, ctx->windowWidth, ctx->windowheight);

    // UI
    CtxUI* ctx_UI = (CtxUI*)calloc(1, sizeof(CtxUI));
    ctx->ctx_UI = ctx_UI;

    // tpl
    Template* tpl = (Template*)calloc(1, sizeof(Template));
    Template_Init(tpl);
    ctx->tpl = tpl;

    // s_id
    S_ID* s_id = (S_ID*)calloc(1, sizeof(S_ID));
    S_ID_Init(s_id);
    ctx->s_id = s_id;
    
    //RP
    RP_Cell* rp_cell =(RP_Cell*)calloc(1,sizeof(RP_Cell));
    RP_Cell_Init(rp_cell);
    ctx->rp_Cell=rp_cell;

}

void ctx_Free(Ctx* ctx) {
    free(ctx->ctx_UI);
    Template_free(ctx->tpl);
    free(ctx->s_id);
}
#endif