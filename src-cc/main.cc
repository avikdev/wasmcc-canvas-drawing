#include <cstdio>

#include <emscripten.h>
#include <emscripten/emscripten.h>
#include <emscripten/console.h>

void HelloFoo();

EM_JS(void, two_alerts, (), {
  alert('hai');
  alert('bai');
});

extern "C" {

EMSCRIPTEN_KEEPALIVE
int addsq(int a, int b) {
    return a*a + b*b;
}

EMSCRIPTEN_KEEPALIVE
int pingIt() {
  return 1;
}

}




int main(int argc, char* argv[]) {
  printf("Started main ...\n");
  emscripten_console_log("In [emscripten_console_log] ...");
  HelloFoo();
  return 0;
}