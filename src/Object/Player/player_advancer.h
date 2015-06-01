
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"


class PlayerAdvancer : public Object {
private:
  Vec3f m_pos;
  Vec3f m_speed;
  Vec3f m_velocity;

  float Max_Velocity = 3000.f;
  float Min_Velocity = 0.f;
  float Max_Speed    = 10.f;
  float Min_Speed    = 0.f;

  void speedManager();
  void move();

public:
  PlayerAdvancer();
  ~PlayerAdvancer() = default;

  void update();
  void draw();

  float& getPos();
};