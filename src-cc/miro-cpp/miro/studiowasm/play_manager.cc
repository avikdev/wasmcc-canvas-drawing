#include "miro/studiowasm/play_manager.h"

namespace miro {

/* static */
PlayManager& PlayManager::GetInstance() {
  static PlayManager* kInstance = ([]{
    return new PlayManager();
  })();
  return *kInstance;
}

SceneManager* PlayManager::CurrentSceneManager() {
  assert(current_scene_ != nullptr);
  return current_scene_;
}

void PlayManager::StartNewScene(const std::string& id) {
  auto scene = std::make_unique<MiroScene>(id);
  scene_managers_.push_back(SceneManager(std::move(scene)));
  current_scene_ = &scene_managers_.back();
}

}  // namespace miro
