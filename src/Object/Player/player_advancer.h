
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"


class PlayerAdvancer : public Object {
private:
  Vec3f pos;
  Vec3f speed;
  Vec3f velocity;

  float Max_Velocity = 10000.f;
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

  Vec3f& getPos();
};