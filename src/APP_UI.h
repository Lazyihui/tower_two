#ifndef APP_UI_H__
#define APP_UI_H__

#include "PN_Login.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct CtxUI
{
    PN_Login *pn_login;
    /* data */
}CtxUI;


// void APP_UI_Free(CtxUI *ctx){
//     if(ctx->pn_login!=NULL){
//         free(ctx->pn_login);
//         ctx->pn_login=NULL;
//     }
//     free(ctx);
// }


//画
void APP_UI_Draw(CtxUI *ctxUI){
    if(ctxUI->pn_login!=NULL){
        PN_Login_Draw(ctxUI->pn_login);
    }
}

//panel 使panel存在
void APP_UI_Login_Open(CtxUI *ctxUI){
    PN_Login *panel = (PN_Login*)calloc(1,sizeof(PN_Login));
    //这里存在了
    PN_Login_Spawn(panel);
    ctxUI->pn_login = panel;
}


#endif
