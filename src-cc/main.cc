#include <cstdio>

#include "drawing2d.h"

#include <emscripten.h>
#include <emscripten/emscripten.h>
#include <emscripten/console.h>

#include <emscripten/val.h>
#include <emscripten/bind.h>

#include <string>

using emscripten::val;

void HelloFoo();

EM_JS(void, two_alerts, (), {
  alert('hai');
  alert('bai');
});


int AddSq(int a, int b) {
    return a*a + b*b;
}


EMSCRIPTEN_BINDINGS(main_module) {
  emscripten::function("addsq", &AddSq);
}


int main(int argc, char* argv[]) {
  printf("Started main ...\n");
  emscripten_console_log("In [emscripten_console_log] ...");
  HelloFoo();
  return 0;
}