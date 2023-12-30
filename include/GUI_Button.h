#ifndef GUI_BUTTON_H__
#define GUI_BUTTON_H__

#include "raylib.h"

typedef struct GUI_Button {

    Rectangle rect;
    Color bgColor;
    Color hoverColor;

    Color fontColor;
    const char* txt;
    char isHover;
} GUI_Button;

GUI_Button GUI_Button_New(Vector2 pos, Vector2 size, Color bg, Color hoverColor, Color fontColor, const char* txt) {

    GUI_Button btn;
    // btn.rect =(Rectangle){.x=pos.x,.y=pos.y,.width=size.x,height=size.y};
    btn.rect.height = size.y;
    btn.rect.width = size.x;
    btn.rect.x = pos.x;
    btn.rect.y = pos.y;
    btn.bgColor = bg;
    btn.hoverColor = hoverColor;
    btn.txt = txt;
    btn.fontColor = fontColor;
    btn.isHover = false;
    return btn;
}

// 是否在里面
char GUI_Button_IsHover(GUI_Button* btn) {
    if (CheckCollisionPointRec(GetMousePosition(), btn->rect)) {
        btn->isHover = true;
        return true;
    } else {
        btn->isHover = false;
        return false;
    }
}

// 是否被点击
char GUI_Button_IsClick(GUI_Button* btn) {
    if (GUI_Button_IsHover(btn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        return true;
    } else {
        return false;
    }
}

// 画button
void GUI_Button_Draw(GUI_Button* btn) {
    if (btn->isHover) {
        DrawRectangleRec(btn->rect, btn->hoverColor);
    } else {
        DrawRectangleRec(btn->rect, btn->bgColor);
    }
    DrawText(btn->txt, btn->rect.x + 10, btn->rect.y + 10, 20, btn->fontColor);
}

#endif