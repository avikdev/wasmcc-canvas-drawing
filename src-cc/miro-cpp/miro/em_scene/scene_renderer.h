#pragma once

#include "miro/sketch/miro_scene.h"
#include "miro/studiowasm/canvas_2dcontext.h"

namespace miro {

class SceneRenderer {
public:
  SceneRenderer() = default;

  void RenderScene(const MiroScene& scene, Canvas2DContext& context);

private:
};

}  // namespace miro
