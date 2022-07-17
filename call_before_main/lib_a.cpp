#include <glog/logging.h>

namespace lib_a {

static auto func = []() { LOG(ERROR) << "init lib_a"; };

static int dummy = (func(), 0);

} // namespace lib_a
