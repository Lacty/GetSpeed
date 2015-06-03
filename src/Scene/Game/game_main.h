
#pragma once
#include "../scene.h"
#include <memory>


class Road;
class Player;
class PlayerAdvancer;
class PlayerMover;
class PlayerRotater;
class SpeedMeter;
class OdoMeter;
class StageRing;

class GameMain : public Scene {
private:
  std::shared_ptr<Road> m_road;
  std::shared_ptr<Player> m_player;
  std::shared_ptr<PlayerAdvancer> m_player_advancer;
  std::shared_ptr<PlayerMover> m_player_mover;
  std::shared_ptr<PlayerRotater> m_player_rotater;
  std::shared_ptr<SpeedMeter> m_speed_meter;
  std::shared_ptr<OdoMeter> m_odo_meter;
  std::shared_ptr<StageRing> m_stage_ring;

public:
  GameMain(SceneMgr*);
  ~GameMain() = default;

  void update();
  void draw();
};