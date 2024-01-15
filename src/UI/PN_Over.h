#ifndef UI_PN_OVER_H__
#define UI_PN_OVER_H__

#include "import.h"

typedef struct PN_Over {
    Rectangle rect_start;
    const char* txt_start;

    Rectangle rect_exit;
    const char* txt_exit;

    bool isClick;
    bool isClickExit;
    void (*onClickStartHandle)(void);
} PN_Over;

// 生成
void PN_Over_Spawn(PN_Over* panel) {
    // panel->btn_Start = GUI_Button_New(Vector2_New(400, 240), Vector2_New(160, 30), BLACK, GRAY, WHITE, "Login");

    panel->rect_start.height = 30;
    panel->rect_start.width = 160;
    panel->rect_start.x = 400;
    panel->rect_start.y = 240;
    panel->txt_start = "again";

}

void PN_Over_Draw(PN_Over* panel) {

    Rectangle bgRect = RectangleNew(0, 0, 960, 540);
    DrawRectangleRec(bgRect, YELLOW);

    // GUI_Button_Draw(&panel->btn_Start);
    panel->isClick = GuiButton(panel->rect_start, panel->txt_start);

}

#endif