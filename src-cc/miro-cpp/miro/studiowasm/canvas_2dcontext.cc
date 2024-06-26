#include "miro/studiowasm/canvas_2dcontext.h"

#include <cmath>

#include <emscripten/console.h>
#include <emscripten/val.h>

#include "absl/container/flat_hash_set.h"
#include "absl/strings/str_join.h"
#include "miro/studiowasm/canvas_2dcontext.h"

namespace miro {

using ::emscripten::val;

Canvas2DContext::Canvas2DContext(emscripten::val ctx)
  : ctx_(std::move(ctx)) {
}

/*
void Canvas2DContext::DrawLine(const Line& line) {
  ctx_.set("strokeStyle", "#44444455");
  ctx_.set("lineWidth", 0.5);
  ctx_.call<void>("beginPath");  // // Start a new path
  ctx_.call<void>("moveTo", line.x1, line.y1);  // Move the pen to (x, y)
  ctx_.call<void>("lineTo", line.x2, line.y2);  // Draw a line to (x, y)
  ctx_.call<void>("stroke"); // Render the path
}

void Canvas2DContext::DrawRect(const Rectangle& rect) {
  ctx_.set("strokeStyle", "#44444433");
  ctx_.set("lineWidth", 0.5);
  float w = rect.x2 - rect.x1;
  float h = rect.y2 - rect.y1;
  ctx_.call<void>("strokeRect", rect.x1, rect.y1, w, h);
}

void Canvas2DContext::DrawEllipse(const Ellipse& ellipse) {
  static const double TWO_PI = 2.0 * acos(-1.L);

  ctx_.set("strokeStyle", "#44444455");
  ctx_.set("lineWidth", 0.5);
  ctx_.call<void>("beginPath");
  ctx_.call<void>("ellipse", ellipse.cx, ellipse.cy, ellipse.rx, ellipse.ry, 0, 0, TWO_PI);
  ctx_.call<void>("stroke");
}
*/

void Canvas2DContext::DrawBoundingBox(float xmin, float ymin, float xmax, float ymax) {
  ctx_.set("lineWidth", 0.5);
  ctx_.call<void>("strokeRect", xmin, ymin, xmax - xmin, ymax - ymin);
}

}  // namespace miro
