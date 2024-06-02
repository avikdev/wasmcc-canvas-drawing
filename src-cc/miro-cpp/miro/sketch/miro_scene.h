#pragma once

#include "miro/sketch/layerstack.h"

namespace miro {

class MiroScene {
public:
  MiroScene() = default;

  void FillDummy();

  const std::vector<LayerStack>& stacks() const {
    return stacks_;
  }

private:
  std::vector<LayerStack> stacks_;
};

}  // namespace miro
