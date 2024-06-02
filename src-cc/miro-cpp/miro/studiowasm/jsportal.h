#include <string>

#include <emscripten/val.h>

namespace miro {

class JSPortal {
public:

  static JSPortal& GetInstance();

  // Generate a UUID string by calling the JS side version.
  std::string uuid();

private:
  JSPortal() = default;

  // The handle to the portal object ("window.portalToCC") in the JS realm.
  emscripten::val portal_;
};

}  // namespac miro
