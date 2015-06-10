
#pragma once
#include "../../MyLib/ci_app.h"
#include "../scene.h"
#include <memory>


class Title : public Scene {
private:
  Vec3f m_rotate;

  // ƒiƒ“ƒoƒŠƒ“ƒO‚¢‚­‚È‚¢
  // ŽžŠÔ‚È‚¢
  std::unique_ptr<Font> font1;
  std::unique_ptr<Font> font2;
  std::unique_ptr<Font> font3;
  std::unique_ptr<Font> font4;

  void camera();

public:
  Title(SceneMgr*);
  ~Title() = default;

  void update();
  void draw();
};