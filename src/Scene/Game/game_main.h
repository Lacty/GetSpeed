
#pragma once
#include "../scene.h"
#include <memory>


class Road;
class Player;
class PlayerAdvancer;
class PlayerRotater;

class GameMain : public Scene {
private:
  std::shared_ptr<Road> m_road;
  std::shared_ptr<Player> m_player;
  std::shared_ptr<PlayerAdvancer> m_player_advancer;
  std::shared_ptr<PlayerRotater> m_player_rotater;

public:
  GameMain(SceneMgr*);
  ~GameMain() = default;

  void update();
  void draw();
};