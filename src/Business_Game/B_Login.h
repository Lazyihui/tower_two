#ifndef BUSINESS_B_LOGIN_H__
#define BUSINESS_B_LOGIN_H__
#include "import.h"

void B_Login_Enter(Ctx* ctx,void (*onClickStartHandle)(void)) {
      APP_UI_Login_Open(ctx->ctx_UI,onClickStartHandle );
    ctx->gameStatus = GAME_STATUS_LOGIN;
}

#endif