#include <spdlog/spdlog.h>

namespace lib_a {

static auto func = []() { spdlog::info("init lib_a"); };

static int dummy = (func(), 0);

} // namespace lib_a
