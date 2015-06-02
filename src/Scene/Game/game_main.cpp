
#include "game_main.h"
#include "../../System/scene_mgr.h"
#include "../../MyLib/graph.h"

#include "../../Object/task.h"
#include "../../Object/Road/road.h"
#include "../../Object/Player/player.h"
#include "../../Object/Player/player_advancer.h"
#include "../../Object/Player/player_mover.h"
#include "../../Object/Player/player_rotater.h"
#include "../../Object/Camera/camera.h"


GameMain::GameMain(SceneMgr* mgr) :
Scene(mgr)
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

  //-------------------------------------------------------
  // Camera‰Šú‰»

  GameCamera::getInstance().create(CameraPersp(getWindowWidth(), getWindowHeight(), 35.f, 0.5f, 5000.f));
  //GameCamera::getInstance().cam().lookAt(Vec3f(0.f, 100.f, 300.f), Vec3f(0.f, 0.f, -500.f));
}


void GameMain::update() {
  Task::getInstance().update();

  GameCamera::getInstance().cam().lookAt(Vec3f(m_player->getPos().x * 0.9,
                                               m_player->getPos().y + 40.f,
                                               m_player->getPos().z + 100.f),
                                         Vec3f(m_player->getPos().x / 1.2f,
                                               -100.f,
                                               m_player->getPos().z -500.f));
}

void GameMain::draw() {
  gl::setMatrices(GameCamera::getInstance().cam());
  Task::getInstance().draw();
}