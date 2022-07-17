#include <glog/logging.h>

static auto func = []() { LOG(ERROR) << "init lib_a"; };

static int dummy = (func(), 0);
