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

// 画时间 金钱

// panel 使panel存在
void APP_UI_Login_Open(CtxUI* ctxUI, void (*onClickStartHandle)(void)) {
    PN_Login* panel = (PN_Login*)calloc(1, sizeof(PN_Login));
    // 这里存在了
    panel->onClickStartHandle = onClickStartHandle;
    PN_Login_Spawn(panel);
    ctxUI->pn_login = panel;
}

// 关闭panel
void APP_UI_Login_Close(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        free(ctxUI->pn_login);
        ctxUI->pn_login = NULL;
    }
}

bool APP_UI_Login_Click(CtxUI* ctxUI) {
    if (ctxUI->pn_login != NULL) {
        return ctxUI->pn_login->isClick;
    }
    return false;
}

#endif
