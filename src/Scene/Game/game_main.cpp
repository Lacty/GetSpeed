
#include "game_main.h"
#include "../../System/scene_mgr.h"
#include "../../MyLib/graph.h"

#include "../../Object/task.h"
#include "../../Object/Road/road.h"
#include "../../Object/Player/player.h"
#include "../../Object/Player/player_advancer.h"
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

  m_player = std::make_shared<Player>();
  Task::getInstance().add(m_player->getName(), m_player);

  GameCamera::getInstance().create(CameraPersp(getWindowWidth(), getWindowHeight(), 35.f, 0.5f, 1000.f));
  GameCamera::getInstance().cam().lookAt(Vec3f(0.f, 0.f, 700.f), Vec3f(0.f, 0.f, 0.f));
}


void GameMain::update() {
  Task::getInstance().update();
}

void GameMain::draw() {
  gl::setMatrices(GameCamera::getInstance().cam());
  Task::getInstance().draw();
}