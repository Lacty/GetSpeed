
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
m_rotate(Vec3f(180, 0, 0)),
isShiftScene(false),
alpha_count(0.f),
fade_count(0.f)
{
  font1 = std::make_unique<Font>(loadAsset("Font/planet.TTF"), 90.f);
  font2 = std::make_unique<Font>("", 40.f);
  font3 = std::make_unique<Font>("", 120.f);
  font4 = std::make_unique<Font>(loadAsset("Font/planet.TTF"), 30.f);
  Score::getInstance().load();

  eye = Vec3f(0, 0, 700);
  target = Vec3f::zero();
  GameCamera::getInstance().cam().lookAt(eye, target);
  
  auto ctx = audio::Context::master();

  audio::SourceFileRef sourceFile = audio::load(loadAsset("Sound/Title/bgm.mp3"));
  audio::BufferRef buffer = sourceFile->loadBuffer();
  bgm = ctx->makeNode(new audio::BufferPlayerNode(buffer));

  gain = ctx->makeNode(new audio::GainNode(1.0f));

  bgm >> gain >> ctx->getOutput();

  ctx->enable();

  gain->setValue(0.14f);
  bgm->setLoopEnabled();
  bgm->start();
}

void Title::shiftScene() {
  if (!isShiftScene) return;
  fade_count += 0.01f;
  gl::pushModelView();
  gl::translate(Vec3f(0, 0, 680));
  gl::rotate(Vec3f(0, 0, 0));
  gl::color(ColorA(1, 1, 1, fade_count));
  gl::drawSolidCircle(Vec2f::zero(), 100, 0);
  gl::popModelView();

  gain->setValue(0.14f - fade_count * 0.1f);

  if (fade_count >= 1.0f) {
    bgm->stop();
    Task::getInstance().clear();
    m_mgr->shiftNextScene(std::make_shared<GameMain>(m_mgr));
  }
}

void Title::update() {
  alpha_count += 0.03f;
  if (Key::get().isPush(KeyEvent::KEY_SPACE)) {
    isShiftScene = true;
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
    gl::drawStringCentered("Press `Space` to Start.", pos4, ColorA(0.6f, 0.6f, 0.6f, std::abs(sin(alpha_count))), *font4);
  }
  gl::popModelView();
  shiftScene();
}