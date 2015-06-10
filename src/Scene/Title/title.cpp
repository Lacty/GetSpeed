
#include "title.h"
#include "../../System/scene_mgr.h"
#include "../../MyLib/graph.h"
#include "../../MyLib/key.h"
#include "../Game/game_main.h"

#include "../../Object/Camera/camera.h"
#include "../../Object/Road/road.h"
#include "../../Object/task.h"
#include "../../Score/score.h"

#include <iostream>


Title::Title(SceneMgr* mgr) :
Scene(mgr),
m_rotate(Vec3f(180, 0, 0))
{
  font1 = std::make_unique<Font>(loadAsset("Font/planet.TTF"), 90.f);
  font2 = std::make_unique<Font>("", 40.f);
  font3 = std::make_unique<Font>("", 120.f);
  font4 = std::make_unique<Font>(loadAsset("Font/planet.TTF"), 30.f);
  Score::getInstance().load();
}

void Title::camera() {
  Vec3f eye = Vec3f(0, 0, 700);
  Vec3f target = Vec3f::zero();
  GameCamera::getInstance().cam().lookAt(eye, target);
}

void Title::update() {
  camera();
  if (Key::get().isPush(KeyEvent::KEY_SPACE)) {
    Task::getInstance().clear();
    m_mgr->shiftNextScene(std::make_shared<GameMain>(m_mgr));
  }
}

void Title::draw() {
  Vec2f pos1   = Vec2f(0, -180);
  Vec2f pos2   = Vec2f(0, 0);
  Vec2f pos3   = Vec2f(0, 40);
  Vec2f pos4   = Vec2f(0, 140);
  Color color  = Color::white();
  gl::pushModelView();
  gl::rotate(m_rotate);
  {
    gl::drawStringCentered("GetSpeed.", pos1, Color(1, 0.5f, 0), *font1);
    gl::drawStringCentered("-HeightScore-", pos2, Color(0.6f, 0.6f, 0.6f), *font2);
    gl::drawStringCentered(std::to_string(Score::getInstance().getFirst()), pos3, Color(0.2f, 0.6f, 1.f), *font3);
    gl::drawStringCentered("Press `Space` to Start.", pos4, Color(0.6f, 0.6f, 0.6f), *font4);
  }
  gl::popModelView();
}