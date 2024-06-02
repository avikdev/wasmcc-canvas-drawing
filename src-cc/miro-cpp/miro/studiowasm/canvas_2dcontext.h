#pragma once

#include <emscripten/val.h>

#include "miro/sketch/geometry.h"

namespace miro {

class Canvas2DContext final {
public:
  explicit Canvas2DContext(emscripten::val ctx);

  void DrawLine(const Line& line);
  void DrawRect(const Rectangle& rect);
  void DrawEllipse(const Ellipse& ellipse);

private:
  emscripten::val ctx_;
};

}  // namespace miro
