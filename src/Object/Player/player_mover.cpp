
#include "../../MyLib/key.h"
#include "../../road_size.h"
#include "player_mover.h"


PlayerMover::PlayerMover() :
m_pos(Vec3f::zero())
{
  m_name = std::string("PlayerMover");
}

PlayerMover::~PlayerMover() {}


void PlayerMover::move() {
  if (Key::get().isPress(KeyEvent::KEY_d)) {
    m_pos.x += Move_Speed;
  } else if (Key::get().isPress(KeyEvent::KEY_a)) {
    m_pos.x -= Move_Speed;
  }
}

void PlayerMover::bound() {
  if (m_pos.x < LeftEdge || m_pos.x > RightEdge) {
    m_pos.x = std::max(m_pos.x, float(LeftEdge));
    m_pos.x = std::min(m_pos.x, float(RightEdge));
  }
}


void PlayerMover::update() {
  move();
  bound();
}

void PlayerMover::draw() {}


float& PlayerMover::getPos() {
  return m_pos.x;
}