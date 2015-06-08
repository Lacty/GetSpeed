
#pragma once
#include "../../MyLib/ci_app.h"
#include "../scene.h"
#include <memory>


class Title : public Scene {
private:
  Vec3f m_rotate;
  std::unique_ptr<Font> font;

  void camera();

public:
  Title(SceneMgr*);
  ~Title() = default;

  void update();
  void draw();
};