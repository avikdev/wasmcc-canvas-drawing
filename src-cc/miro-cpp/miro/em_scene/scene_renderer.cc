#include "miro/em_scene/scene_renderer.h"

#include <type_traits>
#include <variant>

#include <emscripten/console.h>

namespace miro {

void SceneRenderer::RenderScene(const MiroScene& scene, Canvas2DContext& context) {
  for (const auto& stack : scene.layer_stacks()) {
    for (const auto& element : stack.elements) {
      const auto [ xmin, ymin, xmax, ymax ] = element->bbox;
      context.DrawBoundingBox(xmin, ymin, xmax, ymax);
    }
  }
}

}  // namespace miro