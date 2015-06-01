
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"


class PlayerMover : public Object {
private:
  Vec3f m_pos;

  // �ړ��͊���g���ƃk���k������
  // �������ƃJ�N���Ă���悤�Ɍ�����
  const float Move_Speed = 3;

  void move();
  void bound();

public:
  PlayerMover();
  ~PlayerMover();

  void update();
  void draw();

  float& getPos();
};