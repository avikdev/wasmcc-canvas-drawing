#include "miro/em_scene/scene_manager.h"


#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/console.h>

namespace miro {
namespace {

using emscripten::val;
using ::emscripten::vecFromJSArray;

void PopulateLayerStack(val js_stack, LayerStack& stack) {
}

}  // namespace

EM_JS(void, log_spec, (val spec), {
  console.log("Logging spec --");
  console.log(spec);
  console.log("Logged spec --");
});
SceneManager::SceneManager(std::unique_ptr<MiroScene> scene)
    : scene_(std::move(scene)) {
}

void SceneManager::ResetFromDummy() {
  scene_->FillDummy();
}

void SceneManager::LoadFromSpecObject(val spec) {
  log_spec(spec);
  //scene_->id_ = spec["id"].as<std::string>();


  std::vector<LayerStack>* scene_stacks = scene_->mutable_stacks();
  std::vector<val> js_stacks = vecFromJSArray<val>(spec["stacks"]);
  scene_stacks->reserve(js_stacks.size());


  for (const auto& js_stack : js_stacks) {
    LayerStack scene_stack;
    emscripten_console_log("stack ======");

    scene_stacks->push_back(std::move(scene_stack));
  }
}

}  // namespace miro
