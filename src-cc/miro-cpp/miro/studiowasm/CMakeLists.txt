add_library(
  miro-studiowasm SHARED
  canvas_2dcontext.h canvas_2dcontext.cc
  jsportal.h jsportal.cc
  util.h util.cc
  scene_module.h scene_module.cc
  scene_renderer.h scene_renderer.cc
)

target_link_libraries(
  miro-studiowasm
  absl::flat_hash_set
  absl::strings
)