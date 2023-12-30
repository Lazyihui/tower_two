#ifndef APP_UI_H__
#define APP_UI_H__

#include "PN_Login.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct CtxUI {
    PN_Login* pn_login;
    /* data */
} CtxUI;

// 释放
void APP_UI_Free(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        free(ctxUI->pn_login);
        ctxUI->pn_login = NULL;
    }
    free(ctxUI);
}

// 画
void APP_UI_Draw(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        PN_Login_Draw(ctxUI->pn_login);
    }
}

//画时间 金钱


// panel 使panel存在
void APP_UI_Login_Open(CtxUI* ctxUI) {
    PN_Login* panel = (PN_Login*)calloc(1, sizeof(PN_Login));
    // 这里存在了
    PN_Login_Spawn(panel);
    ctxUI->pn_login = panel;
}

// 点击
bool APP_UI_Login_IsStartClick(CtxUI* ctxUI) {
    PN_Login* panel = ctxUI->pn_login;
    if (panel != NULL) {
        // 0 or 1
        return PN_Login_IsStartClick(panel);
    }
    // 0
    return false;
}

// 关闭panel
void APP_UI_Login_Close(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        free(ctxUI->pn_login);
        ctxUI->pn_login = NULL;
    }
}




#endif
