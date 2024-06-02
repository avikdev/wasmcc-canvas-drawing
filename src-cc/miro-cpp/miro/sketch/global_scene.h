#pragma once

#include <memory>
#include <string>

#include "miro/sketch/miro_scene.h"

namespace miro {

class GlobalScene {

public:
  static bool StartNewScene(const std::string& uid);

  static MiroScene* GetCurrentScene(const std::string& uid);
  

private:
  static GlobalScene& GetInstance();

  // No public instantiation.
  GlobalScene() = default;

  void ResetScene(const std::string& uid, std::unique_ptr<MiroScene> scene);
  MiroScene* ValidateAndGet(const std::string& uid);

  std::string scene_uid_;
  bool is_scene_modified_ {false};
  std::unique_ptr<MiroScene> scene_;
};

}  // namespace miro