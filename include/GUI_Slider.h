#ifndef GUI_SILDER_H__
#define GUI_SILDER_H__

#include "raylib.h"

typedef struct GUI_Slider {
    Color bgColor;
    Color fgColor;
    Rectangle bgRect;
    Rectangle fgRect;

    float value;
    float maxValue;

} GUI_Slider;

GUI_Slider GUI_Slider_New(Color bgcolor, Color fgColor, Rectangle bgRect, Rectangle fgRect, float value,
                          float maxValue) {

    GUI_Slider slider;
    slider.bgColor=bgcolor;
    slider.bgRect=bgRect;
    slider.fgColor=fgColor;
    slider.fgRect=fgRect;
    slider
    
}

#endif