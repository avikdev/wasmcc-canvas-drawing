#pragma once

#include <emscripten/val.h>

namespace miro {

class Canvas2DContext final {
public:
  explicit Canvas2DContext(emscripten::val ctx);

  void DrawBoundingBox(float xmin, float ymin, float xmax, float ymax);

private:
  emscripten::val ctx_;
};

}  // namespace miro
