
#include "../../MyLib/graph.h"
#include "../task.h"
#include "road.h"


Road::Road() {
  m_name = std::string("Road");

  // 立方体の頂点座標を用意
  Vec3f vertices[] = {
    { -1, -1, -1 }, { 1, 1, -1 }, { 1, -1, -1 },
    { -1, -1, -1 }, { -1, 1, -1 }, { 1, 1, -1 },

    { -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 },
    { -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 },

    { 1, -1, -1 }, { 1, 1, -1 }, { 1, 1, 1 },
    { 1, -1, -1 }, { 1, 1, 1 }, { 1, -1, 1 },

    { -1, -1, -1 }, { -1, -1, 1 }, { -1, 1, 1 },
    { -1, -1, -1 }, { -1, 1, 1 }, { -1, 1, -1 },

    { -1, -1, -1 }, { 1, -1, 1 }, { -1, -1, 1 },
    { -1, -1, -1 }, { 1, -1, -1 }, { 1, -1, 1 },

    { 1, 1, 1 }, { -1, 1, 1 }, { -1, -1, 1 },
    { 1, 1, 1 }, { -1, -1, 1 }, { 1, -1, 1 },
  };
  m_mesh.appendVertices(&vertices[0],
                      sizeof(vertices) / sizeof(vertices[0]));
  // 要素数*一つの要素のデータサイズ / 要素ひとつのデータサイズ = verticesの要素数

  // 立方体の頂点色を用意
  Color colors[] = {
    { 0, 1, 1 }, { 0, 1, 1 }, { 0, 1, 1 },
    { 0, 1, 1 }, { 0, 1, 1 }, { 0, 1, 1 },

    { 1, 0, 0 }, { 1, 0, 0 }, { 1, 0, 0 },
    { 1, 0, 0 }, { 1, 0, 0 }, { 1, 0, 0 },

    { 0, 1, 0 }, { 0, 1, 0 }, { 0, 1, 0 },
    { 0, 1, 0 }, { 0, 1, 0 }, { 0, 1, 0 },

    { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 },
    { 0, 0, 1 }, { 0, 0, 1 }, { 0, 0, 1 },

    { 1, 1, 0 }, { 1, 1, 0 }, { 1, 1, 0 },
    { 1, 1, 0 }, { 1, 1, 0 }, { 1, 1, 0 },

    { 1, 0, 1 }, { 1, 0, 1 }, { 1, 0, 1 },
    { 1, 0, 1 }, { 1, 0, 1 }, { 1, 0, 1 },
  };
  m_mesh.appendColorsRgb(&colors[0], sizeof(colors) / sizeof(colors[0]));

  // 描画頂点を用意
  uint32_t indices[] = {
    0, 1, 2,
    3, 4, 5,

    6, 7, 8,
    9, 10, 11,

    12, 13, 14,
    15, 16, 17,

    18, 19, 20,
    21, 22, 23,

    24, 25, 26,
    27, 28, 29,

    30, 31, 32,
    33, 34, 35,
  };
  m_mesh.appendIndices(&indices[0], sizeof(indices) / sizeof(indices[0]));

  // 頂点の法線をCinderに計算してもらう
  m_mesh.recalculateNormals();

  m_camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                         35.0f, 0.5, 800.f);
  m_camera.lookAt(Vec3f(0.f, 0.f, 700.f),
                  Vec3f(0.f, 0.f, 0.f));

  gl::enable(GL_CULL_FACE);

  ry = 0.0f;
}


void Road::update() {
  ry += 0.6f;
}

void Road::draw() {
  //ly::drawCircle(Vec2f(0, 0), 50, 50, Color::white());

  gl::setMatrices(m_camera);
  gl::rotate(Vec3f(0, ry, 0));
  gl::scale(50, 50, 50);
  gl::draw(m_mesh);
}