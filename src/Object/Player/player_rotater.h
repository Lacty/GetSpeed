
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"


class PlayerRotater : public Object {
private:
  Vec3f m_rotate;

  const float Rot_Speed = 1.4f;
  const float Bound_Left = -14.f;
  const float Bound_Right = 14.f;

  void lean();
  void bound();

public:
  PlayerRotater();
  ~PlayerRotater();

  void update();
  void draw();

  Vec3f& getRotate();
};