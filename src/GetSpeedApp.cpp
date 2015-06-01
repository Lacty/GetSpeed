
#include "MyLib/window_size.h"
#include "MyLib/ci_app.h"
#include "MyLib/mouse.h"
#include "MyLib/key.h"
#include "cinder/Rand.h"

#include "System/scene_mgr.h"
#include "Object/task.h"


class GetSpeedApp : public AppNative {
private:
  SceneMgr scene;

public:
  void mouseDown(MouseEvent event) {
    Mouse::get().PushEvent(event);
  }
  void mouseUp(MouseEvent event) {
    Mouse::get().PullEvent(event);
  }
  void mouseMove(MouseEvent event) {
    Mouse::get().MoveEvent(event);
  }
  void keyDown(KeyEvent event) {
    Key::get().setKeyPush(event.getCode());
    Key::get().setKeyPress(event.getCode());
  }
  void keyUp(KeyEvent event) {
    Key::get().popKeyPress(event.getCode());
    Key::get().setKeyPull(event.getCode());
  }

  void setup();

  void update();
  void draw();
};

void GetSpeedApp::setup() {
  setWindowSize(int(WindowSize::Width),
                int(WindowSize::Height));
  Mouse::get();
  Key::get();
  Task::getInstance();
  Rand::randomize();

  gl::enableAlphaBlending();
}

void GetSpeedApp::update() {
  scene.update();
}

void GetSpeedApp::draw() {
  gl::clear(Color(0.94f, 0.94f, 0.94f));

  scene.draw();

  Mouse::get().flashInput();
  Key::get().flashInput();
}

CINDER_APP_NATIVE(GetSpeedApp, RendererGl)
