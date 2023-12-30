#ifndef PN_LOGIN_H__
#define PN_LOGIN_H__

#include "../include/raylib.h"
#include "../include/raygui.h"
#include "../include/GUI_Button.h"
#include "Common.h"

typedef struct PN_Login {
    GUI_Button btn_Start;
    
} PN_Login;


//生成
void PN_Login_Spawn(PN_Login *panel){
    panel->btn_Start=GUI_Button_New(Vector2_New(480,270),Vector2_New(160,30),BLACK,GRAY,WHITE,"Login");
}

void PN_Login_Draw(PN_Login *panel ){
    GUI_Button_Draw(&panel->btn_Start);
    // GuiButton(panel->btn_Start.rect, panel->btn_Start.txt);
}

bool PN_Login_IsStartClick(PN_Login *panel ){
    return GUI_Button_IsClick(&panel->btn_Start);
}











#endif