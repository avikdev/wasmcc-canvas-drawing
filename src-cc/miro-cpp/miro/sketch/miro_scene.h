#pragma once

#include <string>

#include "miro/sketch/layer_stack.h"
#include "miro/sketch/layer_element.h"

namespace miro {

class MiroScene {
public:
  explicit MiroScene(const std::string& id);

  const std::string& id() const {
    return id_;
  }

  void FillDummy();

  const std::vector<LayerStack>& layer_stacks() const {
    return stacks_;
  }

  const std::vector<LayerStack>& layer_stacks() const {
    return stacks_;
  }

  std::vector<LayerStack>* mutable_stacks() {
    return &stacks_;
  }

  const std::string id_;
  std::vector<LayerStack> stacks_;
};

}  // namespace miro
