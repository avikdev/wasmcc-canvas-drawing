#pragma once

#include <variant>

namespace miro {

struct Rectangle {
  float x1, y1, x2, y2;
};

struct Ellipse {
  float cx, cy, rx, ry;
};

struct Line {
  float x1, y1, x2, y2;
};

using Geometry = std::variant<
    Line,
    Rectangle,
    Ellipse>;

}  // namespace miro
