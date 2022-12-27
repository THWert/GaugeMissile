#include "framework.h"

Utility::RECT::RECT(Vector2 pivot, Vector2 scale)
{
}

Utility::CIRCLE::CIRCLE(Vector2 pivot, Vector2 scale)
{
}

bool Utility::IntersectRectCoord(RECT & rc, Vector2 coord)
{
    return false;
}

bool Utility::IntersectRectRect(RECT & rc1, RECT & rc2)
{
    return false;
}

bool Utility::IntersectRectRect(GameObject* ob1, GameObject* ob2)
{
    return false;
}

bool Utility::IntersectRectCircle(RECT & rc, CIRCLE & cc)
{
    return false;
}

bool Utility::IntersectCircleCoord(CIRCLE & cc, Vector2 coord)
{
    return false;
}

bool Utility::IntersectCircleCircle(CIRCLE & cc1, CIRCLE & cc2)
{
    return false;
}

float Utility::DirToRadian(Vector2 Dir)
{
    //만약 단위벡터가 아니라면
    Dir.Normalize();
    return atan2f(Dir.y, Dir.x);
}
