#include <spdlog/spdlog.h>

namespace lib_b {

static auto func = []() { spdlog::info("init lib_b"); };

struct Temp {
  Temp() { func(); }
};

static auto tmp = Temp();

} // namespace lib_b
