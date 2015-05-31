
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"


class PlayerRotater : public Object {
private:
  Vec3f m_rotate;

  const float Rot_Speed = 0.6f;
  const float Bound_Left = -20.f;
  const float Bound_Right = 20.f;

  void lean();
  void bound();

public:
  PlayerRotater();
  ~PlayerRotater();

  void update();
  void draw();

  Vec3f& getRotate();
};