#pragma once

#include <string>
#include <variant>

#include "miro/sketch/basic_shapes.h"

namespace miro {

struct BoundingBox {
  float xmin{0};
  float ymin{0};
  float xmax{0};
  float ymax{0};
};

enum LayerElementType {
  BASIC_SHAPE = 0,
};

struct LayerElement {
  std::string id;
  BoundingBox bbox;
  LayerElementType type =  BASIC_SHAPE;
  std::variant<BasicShape> details;
};

}  // namespace miro
