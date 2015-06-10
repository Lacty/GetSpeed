
#include "player_advancer.h"
#include "../../MyLib/key.h"
#include "player_life.h"
#include "../task.h"


PlayerAdvancer::PlayerAdvancer() :
m_pos(Vec3f::zero()),
m_speed(Vec3f::zero()),
m_velocity(Vec3f::zero())
{
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
    m_speed.z = Max_Speed / 5;
  } else if ((m_velocity.z >= (Max_Velocity / 10)) && (m_velocity.z < Max_Velocity)) {
    m_speed.z = Max_Speed / 20;
  } else if (m_velocity.z >= Max_Velocity) {
    m_speed.z = Max_Speed / 80;
  }
}

void PlayerAdvancer::move() {
  if (Key::get().isPress(KeyEvent::KEY_w) && p_life->getLife() > 0) {
    //-----------------------------------------------------
    // �f�o�b�O�p x �������ƃX�s�[�hUp
    if (Key::get().isPush(KeyEvent::KEY_x)) m_speed.z = 500;
    m_velocity.z += m_speed.z;
  } else if (m_velocity.z > 1) {
    m_velocity.z *= 0.98f;
    if (m_velocity.z <= 30) {
      m_velocity.z = 0.0f;
    }
  }
  m_pos.z -= m_velocity.z;
}

void PlayerAdvancer::update() {
  if (p_life == nullptr) {
    p_life = std::dynamic_pointer_cast<PlayerLife>(Task::getInstance().find("PlayerLife"));
  }
  speedManager();
  move();
}

void PlayerAdvancer::draw() {}

float& PlayerAdvancer::getPos() {
  return m_pos.z;
}

float& PlayerAdvancer::getSpeed() {
  return m_velocity.z;
}