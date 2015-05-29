
#pragma once
#include "../../MyLib/ci_app.h"
#include "cinder/TriMesh.h"


class Model {
private:
  Model() = default;

  struct Face {
    Vec3f v1, v2, v3;
    ColorA color;
  };
  std::vector<Face> faces;

  TriMesh m_mesh;

public:
  static Model& get() {
    static Model model;
    return model;
  }

  void set(const std::string&);
  TriMesh& getMesh();
  void drawWire();
};