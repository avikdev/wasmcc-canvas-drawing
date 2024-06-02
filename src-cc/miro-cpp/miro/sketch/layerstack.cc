#include "miro/sketch/layerstack.h"

namespace miro {

LayerStack::LayerStack() {

}

void LayerStack::AddGeometry(Geometry&& geom) {
  geoms_.push_back(std::move(geom));
}

}  // namespace miro
