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



#endif
