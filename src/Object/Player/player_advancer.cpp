
#include "player_advancer.h"
#include "../../MyLib/key.h"


PlayerAdvancer::PlayerAdvancer() :
pos(Vec3f::zero()),
speed(Vec3f::zero()),
velocity(Vec3f::zero()) {
  m_name = std::string("PlayerAdvancer");
}


// �X�s�[�h���o��قǐ��i�͂����炷����
// ��肢�v�Z�����v�����Ȃ������̂ł��艟����
// ��F���i�͂�10�@�ő�X�s�[�h��1000�Ƃ���
// �X�s�[�h��0~400�̊� ���i�͂�10
// 400~700�̊� ���i�͂�7
void PlayerAdvancer::speedManager() {
  if ((velocity.z >= Min_Velocity) && (velocity.z < (Max_Velocity / 10) * 4)) {
    speed.z = Max_Speed;
  } else if ((velocity.z >= (Max_Velocity / 10) * 4) && (velocity.z < (Max_Velocity / 10) * 7)) {
    speed.z = Max_Speed / 3 * 2;
  } else if ((velocity.z >= (Max_Velocity / 10) * 7) && (velocity.z < (Max_Velocity / 10) * 9)) {
    speed.z = Max_Speed / 4;
  } else if ((velocity.z >= (Max_Velocity / 10)) && (velocity.z < Max_Velocity)) {
    speed.z = Max_Speed / 10;
  }
}

void PlayerAdvancer::move() {
  if (Key::get().isPress(KeyEvent::KEY_w)) {
    velocity.z += speed.z;
  } else if (velocity.z > 0) {
    velocity.z *= 0.98f;
  }
  pos.z += velocity.z;
}

void PlayerAdvancer::update() {
  speedManager();
  move();
}

void PlayerAdvancer::draw() {
  console() << velocity.z << std::endl;
}

Vec3f& PlayerAdvancer::getPos() {
  return pos;
}