add_library(
  miro-sketch SHARED
  geometry.h
  global_scene.h global_scene.cc
  layerstack.h layerstack.cc
  miro_scene.h miro_scene.cc

)

target_link_libraries(
  miro-sketch
  absl::flat_hash_set
  absl::strings
)
