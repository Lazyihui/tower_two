#ifndef CTX_H__
#define CTX_H__

#include "E_Camera.h"
#include "../include/raylib.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Ctx {

    int windowWidth;
    int windowheight;

    // Camera
    E_Camera cam;

} Ctx;

void ctx_Inti(Ctx* ctx) {

    ctx->windowWidth=960;
    ctx->windowheight=540;

    CameraEntity_Init(&ctx->cam,ctx->windowWidth,ctx->windowheight);

}

void ctx_Free(Ctx*ctx){
}
#endif