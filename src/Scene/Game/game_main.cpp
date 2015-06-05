
#include "game_main.h"
#include "../../System/scene_mgr.h"
#include "../../MyLib/graph.h"

#include "../../Object/task.h"
#include "../../Object/Road/road.h"
#include "../../Object/Player/player.h"
#include "../../Object/Player/player_advancer.h"
#include "../../Object/Player/player_mover.h"
#include "../../Object/Player/player_rotater.h"
#include "../../Object/Meter/Speed/speed_meter.h"
#include "../../Object/Meter/Odo/odo_meter.h"
#include "../../Object/Ring/stage_ring.h"
#include "../../Object/TimeCount/time_counter.h"

#include "../../Object/Camera/camera.h"


GameMain::GameMain(SceneMgr* mgr) :
Scene(mgr)
{
  //-------------------------------------------------------
  // Taskへの追加

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

  m_speed_meter = std::make_shared<SpeedMeter>();
  Task::getInstance().add(m_speed_meter->getName(), m_speed_meter);

  m_odo_meter = std::make_shared<OdoMeter>();
  Task::getInstance().add(m_odo_meter->getName(), m_odo_meter);

  m_stage_ring = std::make_shared<StageRing>();
  Task::getInstance().add(m_stage_ring->getName(), m_stage_ring);

  m_counter = std::make_shared<TimeCounter>();
  Task::getInstance().add(m_counter->getName(), m_counter);

  //-------------------------------------------------------
  // Camera初期化

  GameCamera::getInstance().create(CameraPersp(getWindowWidth(), getWindowHeight(), 35.f, 0.5f, 5000.f));
}


void GameMain::cameraMove() {
  Vec3f eye;
  Vec3f target;

  eye = Vec3f(m_player->getPos().x * 0.9,
              m_player->getPos().y + 40.f,
              m_player->getPos().z + 100.f);

  target = Vec3f(m_player->getPos().x / 1.2f,
                 -100.f,
                 m_player->getPos().z - 500.f);

  GameCamera::getInstance().cam().lookAt(eye, target);
}

void GameMain::update() {
  m_starter.update();
  if (m_starter.isStart()) {
    Task::getInstance().update();
  }
  cameraMove();
}

void GameMain::draw() {
  gl::setMatrices(GameCamera::getInstance().cam());
  Task::getInstance().draw();
  m_starter.draw();
}