#ifndef PN_LOGIN_H__
#define PN_LOGIN_H__

#include "import.h"

typedef struct PN_Login {
    Rectangle rect_start;
    const char* txt_start;

    Rectangle rect_exit;
    const char* txt_exit;

    bool isClick;
    bool isClickExit;
    void (*onClickStartHandle)(void);
} PN_Login;

// 生成
void PN_Login_Spawn(PN_Login* panel) {
    // panel->btn_Start = GUI_Button_New(Vector2_New(400, 240), Vector2_New(160, 30), BLACK, GRAY, WHITE, "Login");

    panel->rect_start.height = 30;
    panel->rect_start.width = 160;
    panel->rect_start.x = 400;
    panel->rect_start.y = 240;
    panel->txt_start = "Login";

    panel->rect_exit.height = 30;
    panel->rect_exit.width = 160;
    panel->rect_exit.x = 400;
    panel->rect_exit.y = 300;
    panel->txt_exit = "EXit";
}

void PN_Login_Draw(PN_Login* panel) {

    Rectangle bgRect = RectangleNew(0, 0, 960, 540);
    DrawRectangleRec(bgRect, YELLOW);

    // GUI_Button_Draw(&panel->btn_Start);
    panel->isClick = GuiButton(panel->rect_start, panel->txt_start);

    panel->isClickExit = GuiButton(panel->rect_exit, panel->txt_exit);
    if (panel->isClick || panel->isClickExit) {
        panel->onClickStartHandle();
    }
}

#endif