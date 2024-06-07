add_library(
  miro-sketch SHARED
  basic_shapes.h basic_shapes.cc
  global_scene.h global_scene.cc
  layer_element.h layer_element.cc
  layer_stack.h layer_stack.cc
  miro_scene.h miro_scene.cc

)

target_link_libraries(
  miro-sketch
  absl::random_random
  absl::flat_hash_set
  absl::strings
)
