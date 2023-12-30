#ifndef CTX_H__
#define CTX_H__

#include "APP_UI.h"
#include "E_Camera.h"
#include "../include/raylib.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Ctx {

    int windowWidth;
    int windowheight;

    // Camera
    E_Camera cam;

    // UI
    CtxUI* ctx_UI;

    //

} Ctx;

void ctx_Inti(Ctx* ctx) {

    ctx->windowWidth = 960;
    ctx->windowheight = 540;

    CameraEntity_Init(&ctx->cam, ctx->windowWidth, ctx->windowheight);

    //UI
    CtxUI *ctx_UI = (CtxUI*)calloc(1,sizeof(CtxUI));
    ctx->ctx_UI = ctx_UI;

    //
}

void ctx_Free(Ctx* ctx) {
}
#endif