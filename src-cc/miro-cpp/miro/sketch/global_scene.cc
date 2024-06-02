#include <cassert>

#include "miro/sketch/global_scene.h"

namespace miro {
namespace {


}  // namespace

/* static */
bool GlobalScene::StartNewScene(const std::string& uid) {
  auto scene = std::make_unique<MiroScene>();
  GlobalScene::GetInstance().ResetScene(uid, std::move(scene));
  return true;
}

/* static */
MiroScene* GlobalScene::GetCurrentScene(const std::string& uid) {
  return GlobalScene::GetInstance().ValidateAndGet(uid);
}

/* static */
GlobalScene& GlobalScene::GetInstance() {
  static GlobalScene* kInstance = ([]{
    return new GlobalScene();
  })();
  return *kInstance;
}

void GlobalScene::ResetScene(const std::string& uid, std::unique_ptr<MiroScene> scene) {
  this->scene_ = std::move(scene);
  this->scene_uid_ = uid;
  this->is_scene_modified_ = false;
}

MiroScene* GlobalScene::ValidateAndGet(const std::string& uid) {
  assert(uid == scene_uid_);
  return scene_.get();
}

}  // namespace miro
