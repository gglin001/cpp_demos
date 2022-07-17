#include <glog/logging.h>

namespace lib_b {

static auto func = []() { LOG(ERROR) << "init lib_b"; };

struct Temp {
  Temp() { func(); }
};

static auto tmp = Temp();

} // namespace lib_b
