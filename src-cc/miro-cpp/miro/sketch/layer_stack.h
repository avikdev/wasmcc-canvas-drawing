#pragma once

#include <memory>
#include <vector>

#include "miro/sketch/layer_element.h"

namespace miro {

struct LayerStack {
  std::vector<std::unique_ptr<LayerElement>> elements;
};

}  // namespace miro
