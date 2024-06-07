#include "miro/em_scene/scene_module.h"

#include <emscripten/bind.h>

#include "miro/sketch/global_scene.h"
#include "miro/em_scene/scene_renderer.h"
#include "miro/studiowasm/util.h"
#include "miro/studiowasm/canvas_2dcontext.h"

namespace miro {
namespace {

using ::emscripten::val;

std::string StartNewScene() {
  // TODO: Sketch to json and return the JSON object.
  std::string uid = GetUUIDString();
  GlobalScene::StartNewScene(uid);

  for (int i = 0; i < 20; ++i) {
    const auto u = GetUUIDString();
    printf("UUID = %s\n", u.c_str());
  }
  return uid;
}

void FillCurrentScene(const std::string& uid) {
  MiroScene* scene = GlobalScene::GetCurrentScene(uid);
  scene->FillDummy();
}

bool ApplySceneToCanvas(const std::string& uid, val context) {
  MiroScene* scene = GlobalScene::GetCurrentScene(uid);
  assert(scene != nullptr);
  auto ctx = Canvas2DContext(std::move(context));
  SceneRenderer().RenderScene(*scene, ctx);
  return true;
}

}  // namespace

void RegisterSceneModuleExports() {
  ::emscripten::function("miroStartNewScene", &StartNewScene);
  ::emscripten::function("miroFillCurrentScene", &FillCurrentScene);
  ::emscripten::function("miroApplySceneToCanvas", &ApplySceneToCanvas);
}

}  // namespace miro