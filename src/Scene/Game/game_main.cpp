
//#include "../Title/title.h"
#include "../Result/result.h"
#include "game_main.h"
#include "../../System/scene_mgr.h"
#include "../../MyLib/graph.h"
#include "../../MyLib/key.h"

#include "../../Object/task.h"
#include "../../Object/Road/road.h"
#include "../../Object/Player/player.h"
#include "../../Object/Player/player_advancer.h"
#include "../../Object/Player/player_mover.h"
#include "../../Object/Player/player_rotater.h"
#include "../../Object/Player/player_effect.h"
#include "../../Object/Meter/Speed/speed_meter.h"
#include "../../Object/Meter/Odo/odo_meter.h"
#include "../../Object/Ring/stage_ring.h"
#include "../../Object/TimeCount/time_counter.h"
#include "../../Object/Booster/booster.h"
#include "../../Object/Block/block.h"
#include "../../Object/Player/player_life.h"

#include "../../Object/Camera/camera.h"
#include "../../Score/score.h"


GameMain::GameMain(SceneMgr* mgr) :
Scene(mgr),
fade_count(0)
{
  //-------------------------------------------------------
  // Task‚Ö‚Ì’Ç‰Á

  m_road = std::make_shared<Road>();
  Task::getInstance().add(m_road->getName(), m_road);

  m_player_advancer = std::make_shared<PlayerAdvancer>();
  Task::getInstance().add(m_player_advancer->getName(), m_player_advancer);

  m_player_mover = std::make_shared<PlayerMover>();
  Task::getInstance().add(m_player_mover->getName(), m_player_mover);

  m_player_rotater = std::make_shared<PlayerRotater>();
  Task::getInstance().add(m_player_rotater->getName(), m_player_rotater);

  m_player = std::make_shared<Player>();
  Task::getInstance().add(m_player->getName(), m_player);

  m_player_effect = std::make_shared<PlayerEffect>();
  Task::getInstance().add(m_player_effect->getName(), m_player_effect);

  m_speed_meter = std::make_shared<SpeedMeter>();
  Task::getInstance().add(m_speed_meter->getName(), m_speed_meter);

  m_odo_meter = std::make_shared<OdoMeter>();
  Task::getInstance().add(m_odo_meter->getName(), m_odo_meter);

  m_stage_ring = std::make_shared<StageRing>();
  Task::getInstance().add(m_stage_ring->getName(), m_stage_ring);

  m_counter = std::make_shared<TimeCounter>();
  Task::getInstance().add(m_counter->getName(), m_counter);

  m_booster = std::make_shared<Booster>();
  Task::getInstance().add(m_booster->getName(), m_booster);

  m_block = std::make_shared<Block>();
  Task::getInstance().add(m_block->getName(), m_block);

  m_player_life = std::make_shared<PlayerLife>();
  Task::getInstance().add(m_player_life->getName(), m_player_life);
}


void GameMain::cameraMove() {
  Vec3f eye;
  Vec3f target;

  eye = Vec3f(m_player->getPos().x * 0.9,
              m_player->getPos().y + 40.f,
              m_player->getPos().z + 100.f + m_booster->getEyePosZ() + m_block->getEyePosZ());

  target = Vec3f(m_player->getPos().x / 1.2f,
                 -100.f,
                 m_player->getPos().z - 500.f);

  GameCamera::getInstance().cam().lookAt(eye, target);
}


bool GameMain::isGameOver() {
  return (m_player_life->getLife() == 0) ? true:false;
}

void GameMain::gameOver() {
  if (!isGameOver()) return;

  fade_count += 0.006f;
  gl::pushModelView();
  gl::translate(Vec3f(m_player->getPos().x, 0, m_player->getPos().z));
  gl::rotate(Vec3f(180, 0, 0));
  gl::color(ColorA(1, 1, 1, fade_count));
  gl::drawSolidCircle(Vec2f::zero(), 100, 0);
  gl::popModelView();

  if (fade_count >= 1.0f) {
    Task::getInstance().clear();
    Score::getInstance().setCurrent(m_player->getDistance());
    m_mgr->shiftNextScene(std::make_shared<Result>(m_mgr));
  }
}

void GameMain::update() {
  m_starter.update();
  if (m_starter.isStart()) {
    Task::getInstance().update();
  }
  cameraMove();
}

void GameMain::draw() {
  Task::getInstance().draw();
  m_starter.draw();
  gameOver();
}