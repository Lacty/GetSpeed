
#include "../../MyLib/graph.h"
#include "player_advancer.h"
#include "player_rotater.h"
#include "../task.h"
#include "player.h"


Player::Player() :
m_model("Normal"),
ry(0.0f)
{
  m_name = std::string("Player");
  advance = std::dynamic_pointer_cast<PlayerAdvancer>(Task::getInstance().find("PlayerAdvancer"));
  rotate = std::dynamic_pointer_cast<PlayerRotater>(Task::getInstance().find("PlayerRotater"));
}


void Player::update() {
  //ry += 0.4f;
}

void Player::draw() {
  gl::pushModelView();

  gl::translate(advance->getPos() * 0.001f);
  gl::scale(Vec3f(40, 40, 40));
  gl::rotate(rotate->getRotate());

  gl::draw(m_model.get());
  m_model.drawWire();

  gl::popModelView();
}