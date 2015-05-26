
#include "title.h"
#include "../../System/scene_mgr.h"
#include "../../MyLib/graph.h"
#include "../../MyLib/key.h"
#include "../Game/game_main.h"

#include "../../Object/Road/road.h"
#include "../../Object/task.h"


Title::Title(SceneMgr* mgr) :
Scene(mgr) {}


void Title::update() {
  if (Key::get().isPush(KeyEvent::KEY_SPACE)) {
    Task::getInstance().clear();
    m_mgr->shiftNextScene(std::make_shared<GameMain>(m_mgr));
  }
}

void Title::draw() {
  Vec2f offset = Vec2f(-190, 0);
  Vec2f pos    = Vec2f(getWindowCenter() + offset);
  Color color  = Color::white();
  float size   = 50.f;
  ly::drawString("Press `Space` to Start", pos, color, size);
}