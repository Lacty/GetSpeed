
#pragma once
#include "../scene.h"
#include <memory>


class Road;

class GameMain : public Scene {
private:
  std::shared_ptr<Road> m_road;

public:
  GameMain(SceneMgr*);
  ~GameMain() = default;

  void update();
  void draw();
};