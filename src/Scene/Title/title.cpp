
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
alpha_count(0.f),
default_font("", 120.f),
planet_font(loadAsset("Font/planet.TTF"), 120.f),
fade_count(0.f),
isShiftScene(false)
{
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
  Vec2f pos1   = Vec2f(0, -240);
  Vec2f pos2   = Vec2f(0, 0);
  Vec2f pos3   = Vec2f(0, 40);
  Vec2f pos4   = Vec2f(0, 400);
  Color color  = Color::white();
  gl::pushModelView();
  gl::rotate(m_rotate);
  {
    gl::pushModelView();
    {
      gl::scale(Vec2f(0.74f, 0.74f));
      gl::drawStringCentered("GetSpeed.", pos1, Color(1, 0.5f, 0), planet_font);
    }
    gl::popModelView();

    gl::pushModelView();
    {
      gl::scale(Vec2f(0.3f, 0.3f));
      gl::drawStringCentered("-HighScore-", pos2, Color(0.6f, 0.6f, 0.6f), default_font);
    }
    gl::popModelView();

    gl::pushModelView();
    {
      gl::scale(Vec2f(0.8f, 0.8f));
      gl::drawStringCentered(std::to_string(Score::getInstance().getFirst()), pos3, Color(0.2f, 0.6f, 1.f), default_font);
    }
    gl::popModelView();

    gl::pushModelView();
    {
      gl::scale(Vec2f(0.3f, 0.3f));
      gl::drawStringCentered("Push `Space` to Start.", pos4, ColorA(0.6f, 0.6f, 0.6f, std::abs(sin(alpha_count))), planet_font);
    }
    gl::popModelView();

    gl::pushModelView();
    {
      gl::translate(Vec2f(330, 200));
      gl::scale(Vec2f(0.24f, 0.24f));
      gl::drawStringRight("Author by Yanai", Vec2f::zero(), Color(1.f, 0.4f, 0.4f), default_font);
    }
    gl::popModelView();
  }
  gl::popModelView();
  shiftScene();
}