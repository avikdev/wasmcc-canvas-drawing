#include "drawing2d.h"


#include <emscripten/bind.h>
#include <emscripten/val.h>

using ::emscripten::val;


Drawing2D::Drawing2D(emscripten::val ctx)
  : ctx_(std::move(ctx)) {
}

void Drawing2D::draw_rect() {
  ctx_.set("fillStyle", "pink");
  ctx_.call<void>("fillRect", 120, 150, 130, 90);
}

bool SetCanvas2DContext(val ctx) {
  val::global("console").call<void>("log", ctx);

  auto draw = Drawing2D(ctx);
  draw.draw_rect();
  return true;

}

EMSCRIPTEN_BINDINGS(draw_module) {
  emscripten::function("SetCanvas2DContext", &SetCanvas2DContext);
}