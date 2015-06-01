
#include "player_advancer.h"
#include "../../MyLib/key.h"


PlayerAdvancer::PlayerAdvancer() :
m_pos(Vec3f::zero()),
m_speed(Vec3f::zero()),
m_velocity(Vec3f::zero()) {
  m_name = std::string("PlayerAdvancer");
}


// �X�s�[�h���o��قǐ��i�͂����炷����
// ��肢�v�Z�����v�����Ȃ������̂ł��艟����
// ��F���i�͂�10�@�ő�X�s�[�h��1000�Ƃ���
// �X�s�[�h��0~400�̊� ���i�͂�10
// 400~700�̊� ���i�͂�7
void PlayerAdvancer::speedManager() {
  if ((m_velocity.z >= Min_Velocity) && (m_velocity.z < (Max_Velocity / 10) * 4)) {
    m_speed.z = Max_Speed;
  } else if ((m_velocity.z >= (Max_Velocity / 10) * 4) && (m_velocity.z < (Max_Velocity / 10) * 7)) {
    m_speed.z = Max_Speed / 3 * 2;
  } else if ((m_velocity.z >= (Max_Velocity / 10) * 7) && (m_velocity.z < (Max_Velocity / 10) * 9)) {
    m_speed.z = Max_Speed / 4;
  } else if ((m_velocity.z >= (Max_Velocity / 10)) && (m_velocity.z < Max_Velocity)) {
    m_speed.z = Max_Speed / 10;
  }
}

void PlayerAdvancer::move() {
  if (Key::get().isPress(KeyEvent::KEY_w)) {
    m_velocity.z += m_speed.z;
  } else if (m_velocity.z > 1) {
    m_velocity.z *= 0.98f;
    if (m_velocity.z <= 1) {
      m_velocity.z = 0.0f;
    }
  }
  m_pos.z -= m_velocity.z;
}

void PlayerAdvancer::update() {
  speedManager();
  move();
}

void PlayerAdvancer::draw() {
  console() << "velocity.z = " << m_velocity.z << std::endl;
}

float& PlayerAdvancer::getPos() {
  return m_pos.z;
}