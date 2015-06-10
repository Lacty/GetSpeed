
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"
#include <memory>


class PlayerLife;

class PlayerMover : public Object {
private:
  std::shared_ptr<PlayerLife> p_life;

  Vec3f m_pos;

  // �ړ��͊���g���ƃk���k������
  // �������ƃJ�N���Ă���悤�Ɍ�����
  const float Move_Speed = 5;

  void move();
  void bound();

public:
  PlayerMover();
  ~PlayerMover();

  void update();
  void draw();

  float& getPos();
};