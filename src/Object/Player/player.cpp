
#include "../../MyLib/graph.h"
#include "player.h"


Player::Player() :
m_model("Normal"),
ry(0.0f)
{
  m_name = std::string("Player");
}


void Player::update() {
  ry += 0.4f;
}

void Player::draw() {
  gl::pushModelView();

  gl::scale(Vec3f(50, 50, 50));
  gl::rotate(Vec3f(0, ry, 0));

  gl::draw(m_model.get());
  m_model.drawWire();

  gl::popModelView();
}