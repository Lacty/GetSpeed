
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
m_scale(Vec3f(40, 40, 40))
{
  m_name  = std::string("Player");
  advance = std::dynamic_pointer_cast<PlayerAdvancer>(Task::getInstance().find("PlayerAdvancer"));
  move    = std::dynamic_pointer_cast<PlayerMover>(Task::getInstance().find("PlayerMover"));
  rotate  = std::dynamic_pointer_cast<PlayerRotater>(Task::getInstance().find("PlayerRotater"));
}


void Player::update() {
  m_pos = Vec3f(move->getPos(),
                0.f,
                advance->getPos() * 0.001f);

  m_rotate = rotate->getRotate();
}

void Player::draw() {
  gl::pushModelView();

  gl::translate(m_pos);
  gl::scale(m_scale);
  gl::rotate(m_rotate);

  gl::draw(m_model.get());
  m_model.drawWire();

  gl::popModelView();
}