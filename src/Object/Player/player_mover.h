
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"


class PlayerMover : public Object {
private:
  Vec3f m_pos;

  // 移動は奇数を使うとヌルヌル動く
  // 偶数だとカクついているように見える
  const float Move_Speed = 7;

  void move();
  void bound();

public:
  PlayerMover();
  ~PlayerMover();

  void update();
  void draw();

  float& getPos();
};