
#pragma once
#include "../MyLib/ci_app.h"


namespace ly {
  bool collisionLineToLine(const Vec2f& p1,
                           const Vec2f& p2,
                           const Vec2f& p3,
                           const Vec2f& p4);
}