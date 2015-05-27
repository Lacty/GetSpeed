
#pragma once
#include "../../MyLib/ci_app.h"
#include "cinder/gl/Light.h"
#include "cinder/TriMesh.h"
#include "cinder/Camera.h"
#include "../object.h"


class Road : public Object {
private:
  TriMesh m_mesh;

  float ry;

public:
  Road();
  ~Road() = default;

  void update();
  void draw();
};