#include "miro/sketch/miro_scene.h"

#include "absl/random/random.h"
#include "absl/strings/str_cat.h"

#include "miro/sketch/layer_element.h"

namespace miro {
namespace {

void FillLayerStack(const int seed, LayerStack& stack) {
  absl::InsecureBitGen gen;
  absl::uniform_int_distribution<int32_t> dist(0, 100000);

  const auto rand_in_dim = [&dist, &gen, &seed](int32_t max) {
    int32_t padding  = static_cast<int32_t>(max * 0.05);
    int32_t range = static_cast<int32_t>(max - padding);
    return static_cast<float>(((dist(gen) + seed) % range) + padding/2.0);
  };

  // make a random bounding box.
  const int w = 800, h = 1200;
  const auto make_random_bbox = [w, h, &rand_in_dim]() -> BoundingBox {
    float x1 = rand_in_dim(w);
    float x2 = rand_in_dim(w);
    float y1 = rand_in_dim(h);
    float y2 = rand_in_dim(h);
    return BoundingBox{
      .xmin = std::min(x1, x2),
      .ymin = std::min(y1, y2),
      .xmax = std::max(x1, x2),
      .ymax = std::max(y1, y2),
    };
  };

  for (int i = 0; i < 200; ++i) {
    const std::string id = absl::StrCat("id-", i);
    const auto bounding_box = make_random_bbox();

    auto basic_shape = BasicShape {
      .type = ((dist(gen) % 3) == 0) ? BasicShape::RECTANGLE : BasicShape::RECTANGLE,
    };
    stack.elements.emplace_back(new LayerElement{
      .id = id,
      .bbox = std::move(bounding_box),
      .type = BASIC_SHAPE,
      .details = std::move(basic_shape),
    });
  }
}

}  // namespace

//------------------------------------------------------------------------------

MiroScene::MiroScene(const std::string& id) : id_(id) {
}

void MiroScene::FillDummy() {
  stacks_.resize(4);
  int seed = 12567;
  for (auto& stack : stacks_) {
    FillLayerStack(seed, stack);
    seed += 37;
  }
}

}  // namespace miro
