#include "miro/studiowasm/jsportal.h"
#include "miro/em_scene/scene_module.h"
#include "miro/studiowasm/studio_module.h"

#include <emscripten.h>
#include <emscripten/emscripten.h>
#include <emscripten/console.h>

#include <emscripten/val.h>
#include <emscripten/bind.h>

#include <string>

using emscripten::val;

int AddSquares(int a, int b) {
    return a*a + b*b;
}

EMSCRIPTEN_BINDINGS(main_module) {
  emscripten::function("AddSquares", &AddSquares);
}

//EMSCRIPTEN_BINDINGS(scene_module) {
//  miro::RegisterSceneModuleExports();
//}

EMSCRIPTEN_BINDINGS(studio_module) {
  miro::RegisterStudioModuleExports();
}

int main(int argc, char* argv[]) {
  emscripten_console_log("In main [emscripten_console_log] ...");
  return 0;
}