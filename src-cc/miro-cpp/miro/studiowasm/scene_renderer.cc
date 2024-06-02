#include "miro/studiowasm/scene_renderer.h"

#include <type_traits>
#include <variant>

#include <emscripten/console.h>

#include "miro/sketch/geometry.h"

namespace miro {

void SceneRenderer::RenderScene(const MiroScene& scene, Canvas2DContext& context) {
  for (const auto& stack : scene.stacks()) {
    for (const auto& geom : stack.geometries()) {
      std::visit([&geom, &context](const auto& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, Line>) {
          context.DrawLine(std::get<Line>(geom));
        } else if constexpr (std::is_same_v<T, Rectangle>) {
          context.DrawRect(std::get<Rectangle>(geom));
        } else if constexpr (std::is_same_v<T, Ellipse>) {
          context.DrawEllipse(std::get<Ellipse>(geom));
        }
      }, geom);
    }
  }
}

}  // namespace miro