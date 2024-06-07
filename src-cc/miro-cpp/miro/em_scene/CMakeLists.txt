add_library(
  miro-emscene SHARED
  scene_manager.h scene_manager.cc
  scene_module.h scene_module.cc
  scene_renderer.h scene_renderer.cc
)

target_link_libraries(
  miro-emscene
  absl::flat_hash_set
  absl::strings
)