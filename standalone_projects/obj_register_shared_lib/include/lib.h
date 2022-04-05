#pragma once

#include <functional>
#include <iostream>
#include <unordered_map>

#define UNUSED __attribute__((unused))

namespace lib {

#define REGISTER(__name, func)                                                 \
  UNUSED static bool unused_##__name = RegisterFunction(#__name, func)

using Function = std::function<void(int)>;

bool RegisterFunction(const std::string &, const Function &);

Function GetFunction(const std::string &);

class NoUse {
public:
  NoUse();
};

} // namespace lib
