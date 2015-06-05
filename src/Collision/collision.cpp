
#include "collision.h"


bool ly::collisionLineToLine(const Vec2f& p1,
                             const Vec2f& p2,
                             const Vec2f& p3,
                             const Vec2f& p4)
{
  if (((p1.x - p2.x) * (p3.y - p1.y) + (p1.y - p2.y) * (p1.x - p3.x)) *
      ((p1.x - p2.x) * (p4.y - p1.y) + (p1.y - p2.y) * (p1.x - p4.x)) < 0) {
    if (((p3.x - p4.x) * (p1.y - p3.y) + (p3.y - p4.y) * (p3.x - p1.x)) *
        ((p3.x - p4.x) * (p2.y - p3.y) + (p3.y - p4.y) * (p3.x - p2.x)) < 0) {
      return true;
    }
  }
  return false;
}