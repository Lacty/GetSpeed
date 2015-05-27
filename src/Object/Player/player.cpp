
#include "../../MyLib/graph.h"
#include "../task.h"
#include "player.h"


Player::Player() {
  m_name = std::string("Player");

  Vec3f vA(-0.5f, 2.f, 0.f);
  Vec3f vB(0.5f, 2.f, 0.f);
  Vec3f vC(2.f, -2.5f, 0.f);
  Vec3f vD(-2.f, -2.5f, 0.f);
  Vec3f vE(-0.5f, -2.5f, -1.f);
  Vec3f vF(0.5f, -2.5f, -1.f);
  Vec3f vG(0.5f, -2.5f, 0.f);
  Vec3f vH(-0.5f, -2.5f, 0.f);

  ColorA color(0.3f, 0.3f, 0.8f, 0.6f);

  faces.push_back({ { vA }, { vE }, { vD }, { color } }); // 1
  faces.push_back({ { vA }, { vF }, { vE }, { color } }); // 2
  faces.push_back({ { vA }, { vB }, { vF }, { color } }); // 3
  faces.push_back({ { vB }, { vC }, { vF }, { color } }); // 4
  faces.push_back({ { vA }, { vD }, { vH }, { color } }); // 5
  faces.push_back({ { vA }, { vH }, { vG }, { color } }); // 6
  faces.push_back({ { vA }, { vG }, { vB }, { color } }); // 7
  faces.push_back({ { vB }, { vG }, { vC }, { color } }); // 8
  faces.push_back({ { vE }, { vH }, { vD }, { color } }); // 9
  faces.push_back({ { vE }, { vF }, { vH }, { color } }); // 10
  faces.push_back({ { vF }, { vE }, { vH }, { color } }); // 11
  faces.push_back({ { vF }, { vC }, { vG }, { color } }); // 12


  ry = 0;
}


void Player::update() {
  ry += 0.2f;
}

void Player::draw() {
  gl::pushModelView();

  float viewing_angle = 0.003f;
  gl::scale(Vec3f(50, 50, 50));
  gl::rotate(Vec3f(0, ry, 0));

  for (auto& face : faces) {
    ly::drawLine(face.v1, face.v2, face.color);
    ly::drawLine(face.v2, face.v3, face.color);
    ly::drawLine(face.v3, face.v1, face.color);
  }

  gl::popModelView();
}