
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
m_rotate(Vec3f(180, 0, 0)),
font1(std::make_unique<Font>("", 80)),
font2(std::make_unique<Font>("", 80))
{
  Score::getInstance().sort();
  for (int i = 0; i < Sentinel; ++i) {
    font_pos[i] = Vec2f(-330, -180 + (i * 100));
    score_pos[i] = Vec2f(100, -180 + (i * 100));
  }
}


void Result::camera() {
  Vec3f eye = Vec3f(0, 0, 700);
  Vec3f target = Vec3f::zero();
  GameCamera::getInstance().cam().lookAt(eye, target);
}

void Result::update() {
  camera();
  if (Key::get().isPush(KeyEvent::KEY_RETURN)) {
    Score::getInstance().saveToJson();
    Task::getInstance().clear();
    m_mgr->shiftNextScene(std::make_shared<Title>(m_mgr));
  }
}

void Result::draw() {
  gl::pushModelView();
  {
    gl::rotate(m_rotate);

    //-----------------------------------------------------
    // Current
    gl::drawString("Current", font_pos[Current], Color::white(), *font1);
    gl::drawStringCentered(std::to_string(Score::getInstance().getCurrent()),
                           score_pos[Current], Color(0.3f, 0.3f, 0.3f), *font2);

    //-----------------------------------------------------
    // First
    gl::drawString("First", font_pos[First], Color::white(), *font1);
    gl::drawStringCentered(std::to_string(Score::getInstance().getFirst()),
                           score_pos[First], Color(0.3f, 0.3f, 0.3f), *font2);

    //-----------------------------------------------------
    // Second
    gl::drawString("Second", font_pos[Second], Color::white(), *font1);
    gl::drawStringCentered(std::to_string(Score::getInstance().getSecond()),
                           score_pos[Second], Color(0.3f, 0.3f, 0.3f), *font2);

    //-----------------------------------------------------
    // Third
    gl::drawString("Third", font_pos[Third], Color::white(), *font1);
    gl::drawStringCentered(std::to_string(Score::getInstance().getThird()),
                           score_pos[Third], Color(0.3f, 0.3f, 0.3f), *font2);
  }
  gl::popModelView();
}