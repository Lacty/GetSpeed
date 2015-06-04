
#include "../../MyLib/graph.h"
#include "player_advancer.h"
#include "player_mover.h"
#include "player_rotater.h"
#include "../task.h"
#include "player.h"


Player::Player() :
m_model("Normal"),
m_pos(Vec3f::zero()),
m_rotate(Vec3f(-90, 0, 0)),
m_scale(Vec3f(8, 8, 8)),
m_angle(0.0f)
{
  m_name  = std::string("Player");
  p_advance = std::dynamic_pointer_cast<PlayerAdvancer>(Task::getInstance().find("PlayerAdvancer"));
  p_move    = std::dynamic_pointer_cast<PlayerMover>(Task::getInstance().find("PlayerMover"));
  p_rotate  = std::dynamic_pointer_cast<PlayerRotater>(Task::getInstance().find("PlayerRotater"));
}


float& Player::pitch() {
  m_angle += 0.08f;
  float sin = std::sin(m_angle) * 0.4;
  return sin;
}

void Player::update() {
  m_pos = Vec3f(p_move->getPos(),
                0.0f,
                p_advance->getPos() * 0.01f);

  m_rotate = p_rotate->getRotate();
}

void Player::draw() {
  gl::pushModelView();

  gl::translate(m_pos.x,
                m_pos.y + pitch(),
                m_pos.z);
  gl::scale(m_scale);
  gl::rotate(m_rotate);

  gl::draw(m_model.get());
  m_model.drawWire();

  gl::popModelView();
}


Vec3f& Player::getPos() {
  return m_pos;
}

float& Player::getSpeed() {
  return p_advance->getSpeed();
}