
#include "../../MyLib/key.h"
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

}


void PlayerMover::update() {
  move();
  //bound();
}

void PlayerMover::draw() {}


float& PlayerMover::getPos() {
  return m_pos.x;
}