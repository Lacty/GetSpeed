
#include "../../MyLib/graph.h"
#include "player_advancer.h"
#include "../task.h"
#include "player.h"


Player::Player() :
m_model("Normal"),
ry(0.0f)
{
  m_name = std::string("Player");
  adv = std::dynamic_pointer_cast<PlayerAdvancer>(Task::getInstance().find("PlayerAdvancer"));
}


void Player::update() {
  //ry += 0.4f;
}

void Player::draw() {
  gl::pushModelView();

  gl::scale(Vec3f(40, 40, 40));
  gl::rotate(Vec3f(0, ry, 0));
  gl::translate((adv->getPos() * 0.001f) / 40);

  gl::draw(m_model.get());
  m_model.drawWire();

  gl::popModelView();
}