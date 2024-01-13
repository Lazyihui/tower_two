#ifndef COMMON_H__
#define COMMON_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../include/raygui.h"
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "../include/style_candy.h"

#define PlogNoArg(x)                                                                                                   \
    printf("%s:%d ", __FILE__, __LINE__);                                                                              \
    printf(x)
#define Plog(x, ...)                                                                                                   \
    printf("%s:%d ", __FILE__, __LINE__);                                                                              \
    printf(x, __VA_ARGS__)

#define std_cell 10
const int std_towerCell = std_cell * 2;

typedef enum ShapeType {
    SHAPE_TYPE_RECT = 1,
    SHAPE_TYPE_CIRCLE = 2,
} ShapeType;

enum GAME_STATUS { GAME_STATUS_LOGIN, GAME_STATUS_GAME, GAME_STATUS_OVER };

Vector2 Vector2_New(float x, float y) {
    Vector2 a;
    a.x = x;
    a.y = y;
    return a;
}

Rectangle RectangleNew(float x, float y, float width, float height) {
    Rectangle r;
    r.x = x;
    r.y = y;
    r.width = width;
    r.height = height;
    return r;
}

// 画文字
void Text_Int(int b, int x, int y, int size, Color color) {
    const char* a = TextFormat("%d", b);
    DrawText(a, x, y, size, color);
}

// 矩形和鼠标的交叉检测
bool IsMouseInsiderectRec(Rectangle rect, Vector2 mousePos) {
    if (mousePos.x >= rect.x && mousePos.x <= rect.x + rect.width && mousePos.y >= rect.y &&
        mousePos.y <= rect.y + rect.height) {
        return true;
    } else {
        return false;
    }
}

bool IsMouseInsideRect(Vector2 rectPos, int width, int height, Vector2 mousePos) {
    if (mousePos.x >= rectPos.x && mousePos.x <= rectPos.x + width && mousePos.y >= rectPos.y &&
        mousePos.y <= rectPos.y + height) {
        return true;
    } else {

        return false;
    }
}

// 圆和圆的交叉检测
bool IsCirlceInsideCircle(float r_a, float r_b, Vector2 pos_a, Vector2 pos_b) {
    Vector2 diff = Vector2Subtract(pos_a, pos_b);
    float lengthsqr = Vector2LengthSqr(diff);
    if (lengthsqr >= (r_a + r_b) * (r_a + r_b)) {
        return false;
    } else {
        return true;
    }
}

#endif