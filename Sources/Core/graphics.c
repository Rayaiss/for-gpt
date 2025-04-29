#include "../../Headers/core/graphics.h"

Rectangle GetScaledCenteredRect(Vector2 textureSize)
{
	float scaleX =(float)GetScreenWidth()/textureSize.x;
	float scaleY =(float)GetScreenHeight()/textureSize.y;

    return (Rectangle){
        .x = GetScreenWidth()/2 - (textureSize.x*scaleX)/2,
        .y = GetScreenHeight()/2 - (textureSize.y*scaleY)/2,
        .width = textureSize.x * scaleX,
        .height = textureSize.y * scaleY
    };
}

