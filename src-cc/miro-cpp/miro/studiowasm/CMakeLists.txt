add_library(
  miro-studiowasm SHARED
  canvas_2dcontext.h canvas_2dcontext.cc
  jsportal.h jsportal.cc
  play_manager.h play_manager.cc
  studio_module.h studio_module.cc
  util.h util.cc
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/scene")

target_link_libraries(
  miro-studiowasm
  absl::flat_hash_set
  absl::strings
)