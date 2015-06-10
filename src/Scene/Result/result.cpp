
#include "result.h"
#include "../../System/scene_mgr.h"
#include "../../Object/Camera/camera.h"
#include "../../Object/task.h"
#include "../../Score/score.h"
#include "../../MyLib/key.h"
#include "../Title/title.h"
#include <iostream>
#include <memory>


Result::Result(SceneMgr* mgr) :
Scene(mgr),
count(0.f),
m_rotate(Vec3f(180, 0, 0)),
font1(std::make_unique<Font>("", 80)),
font2(std::make_unique<Font>("", 80))
{
  Score::getInstance().sort();
  for (int i = 0; i < Sentinel; ++i) {
    font_pos[i] = Vec2f(-330, -180 + (i * 100));
    score_pos[i] = Vec2f(100, -180 + (i * 100));
  }

  auto ctx = audio::Context::master();

  audio::SourceFileRef sourceFile = audio::load(loadAsset("Sound/Result/bgm.mp3"));
  audio::BufferRef buffer = sourceFile->loadBuffer();
  bgm = ctx->makeNode(new audio::BufferPlayerNode(buffer));

  gain = ctx->makeNode(new audio::GainNode(1.0f));

  bgm >> gain >> ctx->getOutput();

  ctx->enable();

  gain->setValue(0.5f);
  bgm->setLoopEnabled();
  bgm->start();
}


void Result::camera() {
  Vec3f eye = Vec3f(0, 0, 700);
  Vec3f target = Vec3f::zero();
  GameCamera::getInstance().cam().lookAt(eye, target);
}

void Result::update() {
  camera();
  star.update();
  if (Key::get().isPush(KeyEvent::KEY_RETURN)) {
    bgm->stop();
    Score::getInstance().saveToJson();
    Task::getInstance().clear();
    m_mgr->shiftNextScene(std::make_shared<Title>(m_mgr));
  }
}

void Result::draw() {
  gl::color(Color(1, 0.6f, 0.0f));
  star.draw();
  count += 0.01f;
  gl::pushModelView();
  {
    gl::rotate(m_rotate);

    //-----------------------------------------------------
    // Current
    gl::drawString("Current", font_pos[Current], Color(std::abs(sin(count)), std::abs(sin(count)), std::abs(sin(count))), *font1);
    gl::pushModelView();
    gl::translate(Vec2f(18, -22));
    gl::scale(Vec2f(0.8f, 0.8f));
    gl::drawStringCentered(std::to_string(Score::getInstance().getCurrent()),
                           score_pos[Current], Color(0.3f, 0.3f, 0.3f), *font2);
    gl::popModelView();

    //-----------------------------------------------------
    // First
    gl::drawString("First", font_pos[First], Color(std::abs(sin(count)*0.6f + 0.2f), std::abs(sin(count)), std::abs(sin(count))), *font1);
    gl::drawStringCentered(std::to_string(Score::getInstance().getFirst()),
                           score_pos[First], Color(0.3f, 0.3f, 0.3f), *font2);

    //-----------------------------------------------------
    // Second
    gl::drawString("Second", font_pos[Second], Color(std::abs(sin(count)), std::abs(sin(count)*0.6f + 0.2f), std::abs(sin(count))), *font1);
    gl::drawStringCentered(std::to_string(Score::getInstance().getSecond()),
                           score_pos[Second], Color(0.3f, 0.3f, 0.3f), *font2);

    //-----------------------------------------------------
    // Third
    gl::drawString("Third", font_pos[Third], Color(std::abs(sin(count)), std::abs(sin(count)), std::abs(sin(count)*0.6f + 0.2f)), *font1);
    gl::drawStringCentered(std::to_string(Score::getInstance().getThird()),
                           score_pos[Third], Color(0.3f, 0.3f, 0.3f), *font2);
  }
  gl::popModelView();
}