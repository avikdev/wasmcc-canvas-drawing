#pragma once

#include <emscripten/val.h>


class Drawing2D final {
public:
  explicit Drawing2D(emscripten::val ctx);

  void draw_rect();

private:
  emscripten::val ctx_;
};
