#include "miro/sketch/miro_scene.h"

namespace miro {

void MiroScene::FillDummy() {
  stacks_.resize(1);
  LayerStack* stack = &stacks_[0];

  auto g1 = Rectangle{
    .x1 = 10,
    .y1 = 134,
    .x2 = 25,
    .y2 = 200,
  };

  auto g2 = Ellipse {
    .cx = 30,
    .cy = 25,
    .rx = 40,
    .ry = 60,
  };

auto g3 = Line {
    .x1 = 60,
    .y1 = 134,
    .x2 = 525,
    .y2 = 200,
  };

  stack->AddGeometry(std::move(g1));
  stack->AddGeometry(std::move(g2));
  stack->AddGeometry(std::move(g3));
}

}  // namespace miro
