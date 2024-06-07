#pragma once

#include <memory>

#include <emscripten/val.h>

#include "miro/sketch/miro_scene.h"

namespace miro {

class SceneManager final {
public:
  explicit SceneManager(std::unique_ptr<MiroScene> scene);

  const std::string scene_id() const {
    return scene_->id();
  }

  const MiroScene& scene() const {
    return *scene_;
  }

  void ResetFromDummy();
  void LoadFromSpecObject(emscripten::val spec);

private:
  std::unique_ptr<MiroScene> scene_;
};

}  // namespace miro
