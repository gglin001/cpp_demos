#include <glog/logging.h>

static auto func = []() { LOG(ERROR) << "init lib_b"; };

struct Temp {
  Temp() { func(); }
};

static auto tmp = Temp();
