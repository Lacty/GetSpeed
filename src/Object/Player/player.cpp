
#include "../../MyLib/graph.h"
#include "../task.h"
#include "player.h"


Player::Player() {
  m_name = std::string("Player");

  Vec3f vA(-0.5f, 2.f, -0.5f);
  Vec3f vB(0.5f, 2.f, -0.5f);
  Vec3f vC(2.f, -2.5f, -0.5f);
  Vec3f vD(-2.f, -2.5f, -0.5f);
  Vec3f vE(-0.5f, -2.5f, 1.f);
  Vec3f vF(0.5f, -2.5f, 1.f);
  Vec3f vG(0.5f, -2.5f, -0.5f);
  Vec3f vH(-0.5f, -2.5f, -0.5f);

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

  Vec3f vertices[] = {
    vA, vD, vE, // 1
    vA, vE, vF, // 2
    vA, vF, vB, // 3
    vB, vF, vC, // 4
    vA, vH, vD, // 5
    vA, vG, vH, // 6
    vA, vB, vG, // 7
    vB, vC, vG, // 8
    vE, vD, vH, // 9
    vE, vH, vF, // 10
    vF, vH, vG, // 11 //
    vF, vG, vC, // 12
  };
  m_mesh.appendVertices(vertices,
                        sizeof(vertices) / sizeof(vertices[0]));

  ColorA cA(1.f, 1.f, 1.f, 0.4f);
  ColorA cB(1.f, 1.f, 1.f, 0.4f);
  ColorA cC(0.4f, 0.6f, 0.8f, 0.4f);
  ColorA cD(0.4f, 0.6f, 0.8f, 0.4f);
  ColorA cE(0.4f, 0.6f, 0.8f, 0.4f);
  ColorA cF(0.4f, 0.6f, 0.8f, 0.4f);
  ColorA cG(0.4f, 0.6f, 0.8f, 0.4f);
  ColorA cH(0.4f, 0.6f, 0.8f, 0.4f);

  ColorA colors[] = {
    cA, cD, cE, // 1
    cA, cE, cF, // 2
    cA, cF, cB, // 3
    cB, cF, cC, // 4
    cA, cH, cD, // 5
    cA, cG, cH, // 6
    cA, cB, cG, // 7
    cB, cC, cG, // 8
    cE, cD, cH, // 9
    cE, cF, cH, // 10
    cF, cH, cG, // 11 //
    cF, cG, cC, // 12
  };
  m_mesh.appendColorsRgba(colors,
                          sizeof(colors) / sizeof(colors[0]));

  uint32_t indices[] = {
    0, 1, 2, // 1
    3, 4, 5, // 2
    6, 7, 8, // 3
    9, 10, 11, // 4
    12, 13, 14, // 5
    15, 16, 17, // 6
    18, 19, 20, // 7
    21, 22, 23, // 8
    24, 25, 26, // 9
    27, 28, 29, // 10
    30, 31, 32, // 11
    33, 34, 35, // 12
  };
  m_mesh.appendIndices(indices,
                       sizeof(indices) / sizeof(indices[0]));
  /*m_mesh.recalculateNormals();*/

  gl::enable(GL_CULL_FACE);
  gl::enableDepthRead();
  gl::enableDepthWrite();

  ry = 0;
}


void Player::update() {
  ry -= 0.4f;
}

void Player::draw() {
  gl::pushModelView();

  gl::scale(Vec3f(50, 50, 50));
  gl::rotate(Vec3f(ry, 0, 0));

  for (auto& face : faces) {
    // ÉèÉCÉÑÅ[ÇÃï`âÊ
    ly::drawLine(face.v1, face.v2, face.color);
    ly::drawLine(face.v2, face.v3, face.color);
    ly::drawLine(face.v3, face.v1, face.color);
  }

  gl::draw(m_mesh);

  gl::popModelView();
}