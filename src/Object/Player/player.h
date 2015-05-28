
#pragma once
#include "../../MyLib/ci_app.h"
#include "cinder/TriMesh.h"
#include "../object.h"


class Player : public Object {
private:
  struct Face {
    Vec3f v1, v2, v3;
    ColorA color;
  };
  std::vector<Face> faces;

  TriMesh m_mesh;

  float ry;

public:
  Player();
  ~Player() = default;

  void update();
  void draw();
};