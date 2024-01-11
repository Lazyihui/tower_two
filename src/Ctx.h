#ifndef CTX_H__
#define CTX_H__

#include "Common.h"
#include "../include/raylib.h"
#include "UI/APP_UI.h"
#include "Entitise/export.h"
#include "Repository/export.h"
#include "Template/export.h"
#include "Service/export.h"

typedef struct Ctx {

    int windowWidth;
    int windowheight;

    int gameStatus;
    // Camera
    E_Camera cam;

    // input
    E_Input *input;

    // UI
    CtxUI* ctx_UI;

    // panel
    PN_Login* pn_Login;

    // tpl
    Template* tpl;

    // id
    S_ID* s_id;

    // RP cell
    RP_Cell* rp_Cell;

    // RP mst
    RP_Mst* rp_mst;
    float mstSpawnTimer;
    float mstSpawnInterval;

} Ctx;

void ctx_Inti(Ctx* ctx) {

    ctx->windowWidth = 960;
    ctx->windowheight = 540;

    ctx->gameStatus = GAME_STATUS_LOGIN;

    // camera
    CameraEntity_Init(&ctx->cam, ctx->windowWidth, ctx->windowheight);

    //input
    E_Input *input=(E_Input*)calloc(1,sizeof(E_Input));
    
    ctx->input=input;

    // UI
    CtxUI* ctx_UI = (CtxUI*)calloc(1, sizeof(CtxUI));
    ctx->ctx_UI = ctx_UI;

    // tpl
    Template* tpl = (Template*)calloc(1, sizeof(Template));
    assert(tpl != NULL);
    Template_Cell_Init(tpl);
    Template_Mst_Init(tpl);
    Template_Tower_Init(tpl);
    ctx->tpl = tpl;

    // s_id
    S_ID* s_id = (S_ID*)calloc(1, sizeof(S_ID));
    S_ID_Init(s_id);
    ctx->s_id = s_id;

    // RP cell
    RP_Cell* rp_cell = (RP_Cell*)calloc(1, sizeof(RP_Cell));
    RP_Cell_Init(rp_cell);
    ctx->rp_Cell = rp_cell;

    // RP mst
    RP_Mst* rp_mst = (RP_Mst*)calloc(1, sizeof(RP_Mst));
    RP_Mst_Init(rp_mst);
    ctx->mstSpawnTimer = 2;
    ctx->mstSpawnInterval = 2;
    ctx->rp_mst = rp_mst;
}

void ctx_Free(Ctx* ctx) {
    free(ctx->ctx_UI);
    Template_free(ctx->tpl);
    free(ctx->s_id);
    RP_Cell_Free(ctx->rp_Cell);
    RP_Mst_Free(ctx->rp_mst);
}
#endif