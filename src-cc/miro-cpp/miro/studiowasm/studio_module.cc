#include "miro/studiowasm/studio_module.h"

#include <emscripten/bind.h>

#include "miro/studiowasm/play_manager.h"
#include "miro/em_scene/scene_renderer.h"

namespace miro {
namespace {

using ::emscripten::val;

void StartNewScene(const std::string& new_scene_id) {
  PlayManager::GetInstance().StartNewScene(new_scene_id);
}

void FillCurrentScene(const std::string& scene_id) {
  auto* manager = PlayManager::GetInstance().CurrentSceneManager();
  assert(manager->scene_id() == scene_id);
  manager->ResetFromDummy();
}

void LoadCurrentScene(const std::string& scene_id, val spec) {
  auto* manager = PlayManager::GetInstance().CurrentSceneManager();
  assert(manager->scene_id() == scene_id);
  manager->LoadFromSpecObject(spec);
}

void ApplySceneToCanvas(const std::string& scene_id, val context) {
  auto* manager = PlayManager::GetInstance().CurrentSceneManager();
  assert(manager->scene_id() == scene_id);
  auto ctx = Canvas2DContext(std::move(context));
  SceneRenderer().RenderScene(manager->scene(), ctx);
}

}  // namespace

void RegisterStudioModuleExports() {
  ::emscripten::function("miroStartNewScene", &StartNewScene);
  ::emscripten::function("miroFillCurrentScene", &FillCurrentScene);
  ::emscripten::function("miroLoadCurrentScene", &LoadCurrentScene);
  ::emscripten::function("miroApplySceneToCanvas", &ApplySceneToCanvas);
}

}  // namespace miro
