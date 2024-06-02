#include "miro/studiowasm/jsportal.h"
#include "miro/studiowasm/util.h"

namespace miro {

std::string GetUUIDString() {
  return JSPortal::GetInstance().uuid();
}

}  // namespace miro