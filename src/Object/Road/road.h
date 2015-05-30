
#pragma once
#include "../../MyLib/ci_app.h"
#include "../Model/model.h"
#include "../object.h"


class Road : public Object {
private:
  Model m_model;

public:
  Road();
  ~Road() = default;

  void update();
  void draw();
};