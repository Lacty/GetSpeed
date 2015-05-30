
#pragma once
#include "../../MyLib/ci_app.h"
#include "cinder/TriMesh.h"


class Model {
private:
  struct Face {
    Vec3f v1, v2, v3;
    ColorA color;
  };
  std::vector<Face> faces;

  TriMesh m_mesh;

public:
  Model(const std::string&);

  TriMesh& get();
  void drawWire() const;
};