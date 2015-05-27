
#pragma once
#include "../scene.h"
#include <memory>


class Road;
class Player;

class GameMain : public Scene {
private:
  std::shared_ptr<Road> m_road;
  std::shared_ptr<Player> m_player;

public:
  GameMain(SceneMgr*);
  ~GameMain() = default;

  void update();
  void draw();
};