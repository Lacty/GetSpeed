
#pragma once
#include "../../Object/Start/starter.h"
#include "../scene.h"
#include <memory>

#include "cinder/audio/Context.h"
#include "cinder/audio/NodeEffects.h"
#include "cinder/audio/SamplePlayerNode.h"

#include "../../Object/StarEffect/star.h"


class Road;
class Player;
class PlayerAdvancer;
class PlayerMover;
class PlayerRotater;
class PlayerEffect;
class SpeedMeter;
class OdoMeter;
class StageRing;
class TimeCounter;
class Booster;
class Block;
class PlayerLife;

class GameMain : public Scene {
private:
  std::shared_ptr<Road>           m_road;
  std::shared_ptr<Player>         m_player;
  std::shared_ptr<PlayerAdvancer> m_player_advancer;
  std::shared_ptr<PlayerMover>    m_player_mover;
  std::shared_ptr<PlayerRotater>  m_player_rotater;
  std::shared_ptr<PlayerEffect>   m_player_effect;
  std::shared_ptr<SpeedMeter>     m_speed_meter;
  std::shared_ptr<OdoMeter>       m_odo_meter;
  std::shared_ptr<StageRing>      m_stage_ring;
  std::shared_ptr<TimeCounter>    m_counter;
  std::shared_ptr<Booster>        m_booster;
  std::shared_ptr<Block>          m_block;
  std::shared_ptr<PlayerLife>     m_player_life;

  audio::BufferPlayerNodeRef bgm;
  audio::GainNodeRef         gain;

  Starter m_starter;

  void cameraMove();

  // リザルト移行の処理：クラス化したいけど時間ないしかたない
  bool isGameOver();
  float fade_count;
  void gameOver();

public:
  GameMain(SceneMgr*);
  ~GameMain() = default;

  void update();
  void draw();
};