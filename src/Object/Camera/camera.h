
#pragma once
#include "../../MyLib/noncopyable.h"
#include "../../MyLib/ci_app.h"
#include "cinder/Camera.h"
#include <memory>


class GameCamera : ly::noncopyable {
private:
  std::unique_ptr<CameraPersp> m_camera;

  GameCamera() = default;

public:
  static GameCamera& getInstance() {
    static GameCamera camera;
    return camera;
  }
  void create(const CameraPersp& camera) {
    m_camera = std::make_unique<CameraPersp>(camera);
  }
  CameraPersp& cam() const {
    return *m_camera;
  }
};