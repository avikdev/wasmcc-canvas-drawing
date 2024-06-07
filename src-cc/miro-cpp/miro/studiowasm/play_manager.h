#pragma once

#include "miro/em_scene/scene_manager.h"

namespace miro {

class PlayManager {

public:
  static PlayManager& GetInstance();

  SceneManager* CurrentSceneManager();

  void StartNewScene(const std::string& id);


private:
  // No public instantiation.
  PlayManager() = default;

  // All managed scenes.
  std::vector<SceneManager> scene_managers_;

  SceneManager* current_scene_ {nullptr};
};

}  // namespace miro
