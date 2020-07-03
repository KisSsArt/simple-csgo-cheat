#pragma once
#include "GlowObject.hpp"


struct Vec2
{
    float x, y;
};

struct Vec3
{
    float x, y, z;
};

struct Vec4
{
    float x, y, z, w;
};

enum Hitbox
{
    HEAD = 8,
    BODY = 6,
    RIGHT_HAND = 39,
    LEFT_HAND = 13,
    RIGHT_LEG = 73,
    LEFT_LEG = 66,
    RIGHT_FOOT = 74,
    LEFT_FOOT = 67
};