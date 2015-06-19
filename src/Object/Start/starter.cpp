
#include "starter.h"


Starter::Starter() :
planet_font(loadAsset("Font/planet.TTF"), 54.0f),
m_count(0),
state(Status::Set)
{
  auto ctx = audio::Context::master();

  audio::SourceFileRef sourceFile1 = audio::load(loadAsset("Sound/GameMain/se_set.wav"));
  audio::BufferRef buffer1 = sourceFile1->loadBuffer();
  se_set = ctx->makeNode(new audio::BufferPlayerNode(buffer1));

  audio::SourceFileRef sourceFile2 = audio::load(loadAsset("Sound/GameMain/se_ready.wav"));
  audio::BufferRef buffer2 = sourceFile2->loadBuffer();
  se_ready = ctx->makeNode(new audio::BufferPlayerNode(buffer2));

  audio::SourceFileRef sourceFile3 = audio::load(loadAsset("Sound/GameMain/se_go.wav"));
  audio::BufferRef buffer3 = sourceFile3->loadBuffer();
  se_go = ctx->makeNode(new audio::BufferPlayerNode(buffer3));

  gain = ctx->makeNode(new audio::GainNode(1.0f));

  se_set >> gain >> ctx->getOutput();
  se_ready >> gain >> ctx->getOutput();
  se_go >> gain >> ctx->getOutput();

  ctx->enable();

  gain->setValue(1.0f);
  isSe[Set] = false;
  isSe[Ready] = false;
  isSe[Go] = false;
}


void Starter::update() {
  if (state == Status::Go) return;
  m_count++;
  const int CountMax = 100;
  if (m_count > CountMax) {
    if (state == Status::Ready) {
      state = Status::Go;
      return;
    }
    state = Status::Ready;
    m_count = 0;
  }
}

void Starter::draw() {
  Vec2f pos = Vec2f(0, -80);
  gl::pushModelView();
  gl::translate(Vec3f(0, -10, -300));
  gl::rotate(Vec3f(180, 0, 0));

  switch (state) {
  case Starter::Set:
    if (!isSe[Set]) {
      se_set->start();
      isSe[Set] = true;
    }
    gl::drawStringCentered("Set.", pos, Color(0.4f, 0.8f, 0.4f), planet_font);
    break;
  case Starter::Ready:
    if (!isSe[Ready]) {
      se_ready->start();
      isSe[Ready] = true;
    }
    gl::drawStringCentered("Ready?.", pos, Color(0.4f, 0.4f, 0.8f), planet_font);
    break;
  case Starter::Go:
    if (!isSe[Go]) {
      se_go->start();
      isSe[Go] = true;
    }
    gl::drawStringCentered("Go!.", pos, Color(0.8, 0.4f, 0.4f), planet_font);
    break;
  default:
    break;
  }
  gl::popModelView();
}

bool Starter::isStart() const {
  return state == Go;
}