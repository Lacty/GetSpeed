
#include "game_main.h"
#include "../../System/scene_mgr.h"
#include "../../MyLib/graph.h"

#include "../../Object/Road/road.h"
#include "../../Object/task.h"


GameMain::GameMain(SceneMgr* mgr) :
Scene(mgr),
m_road(std::make_shared<Road>())
{
  Task::getInstance().add(m_road->getName(),
                          m_road);
}


void GameMain::update() {
  Task::getInstance().update();
}

void GameMain::draw() {
  Task::getInstance().draw();
}