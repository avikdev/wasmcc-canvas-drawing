#pragma once

#include <vector>

#include "miro/sketch/geometry.h"

namespace miro {

class LayerStack {
public:
  LayerStack();

  void AddGeometry(Geometry&& geom);

  const std::vector<Geometry>& geometries() const {
    return geoms_;
  }

private:
  std::vector<Geometry> geoms_;
};

}  // namespace miro
