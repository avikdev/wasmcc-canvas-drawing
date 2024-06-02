#include "miro/studiowasm/jsportal.h"

namespace miro {
namespace {

using ::emscripten::EM_VAL;
using ::emscripten::val;

emscripten::val GetPortalOrDie() {
  // The global this could be window or worker.
  emscripten::val globalThis = val::global("globalThis");
  assert(globalThis.hasOwnProperty("portalToCC"));
  //EM_VAL portal = globalThis["portalToCC"].as_handle();
  //return portal;
  emscripten::val portal = globalThis["portalToCC"];

  // Validate that the portal object has the necessary methods.
  assert(portal.hasOwnProperty("uuid"));

  return portal;
}

}  // namespace

/* static */
JSPortal& JSPortal::GetInstance() {
  static JSPortal* kInstance = ([]{
    JSPortal* const portal = new JSPortal();
    portal->portal_ = GetPortalOrDie();
    return portal;
  })();
  return *kInstance;
}

std::string JSPortal::uuid() {
  return portal_.call<std::string>("uuid");
}

}  // namespac miro
