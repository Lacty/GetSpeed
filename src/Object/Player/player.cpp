
#include "../../MyLib/graph.h"
#include "../task.h"
#include "player.h"
#include "../Model/model.h"


Player::Player() {
  m_name = std::string("Player");
  Model::get().set("a");

  ry = 0;
}


void Player::update() {
  ry += 0.4f;
}

void Player::draw() {
  gl::pushModelView();

  gl::scale(Vec3f(50, 50, 50));
  gl::rotate(Vec3f(ry, 0, 0));

  gl::draw(Model::get().getMesh());
  Model::get().drawWire();

  gl::popModelView();
}