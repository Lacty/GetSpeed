
#include "title.h"
#include "../../System/scene_mgr.h"
#include "../../MyLib/graph.h"
#include "../../MyLib/key.h"
#include "../Game/game_main.h"

#include "../../Object/Camera/camera.h"
#include "../../Object/Road/road.h"
#include "../../Object/task.h"


Title::Title(SceneMgr* mgr) :
Scene(mgr),
m_rotate(Vec3f(180, 0, 0))
{
  font = std::make_unique<Font>(loadAsset("Font/planet.TTF"), 30.0f);
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
  Vec2f pos    = Vec2f(0, 80);
  Color color  = Color::white();
  gl::pushModelView();
  gl::rotate(m_rotate);
  gl::drawStringCentered("Press `Space` to Start.", pos, Color(1, 0.5f, 0), *font);
  gl::popModelView();
}