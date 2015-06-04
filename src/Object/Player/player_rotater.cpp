
#include "../../MyLib/key.h"
#include "player_rotater.h"


PlayerRotater::PlayerRotater() :
m_rotate(Vec3f(-90, 0, 0))
{
  m_name = std::string("PlayerRotater");
}

PlayerRotater::~PlayerRotater() {}


void PlayerRotater::lean() {
  if (Key::get().isPress(KeyEvent::KEY_d)) {
    m_rotate.y += Rot_Speed;
  } else if (Key::get().isPress(KeyEvent::KEY_a)) {
    m_rotate.y -= Rot_Speed;
  } else
  {
    m_rotate.y *= 0.93f;
  }
}

void PlayerRotater::bound() {
  if (m_rotate.y < Bound_Left ||
      m_rotate.y > Bound_Right)
  {
    m_rotate.y = std::max(m_rotate.y, Bound_Left);
    m_rotate.y = std::min(m_rotate.y, Bound_Right);
  }
}

void PlayerRotater::update() {
  lean();
  bound();
}

void PlayerRotater::draw() {}


Vec3f& PlayerRotater::getRotate() {
  return m_rotate;
}