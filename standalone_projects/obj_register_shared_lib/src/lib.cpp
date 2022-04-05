#include "lib.h"

#include <iostream>
#include <unordered_map>

namespace lib {

NoUse::NoUse() { std::cout << "new NoUse class" << std::endl; }

std::unordered_map<std::string, Function> &Functions() {
  static std::unordered_map<std::string, Function> symbol_handlers;
  return symbol_handlers;
}

bool RegisterFunction(const std::string &name, const Function &func) {
  std::cout << "__register " << name << std::endl;
  if (Functions().count(name) != 0) {
    return false;
  }
  return Functions().emplace(name, func).second;
}

Function GetFunction(const std::string &name) {
  auto it = Functions().find(name);
  if (it != Functions().end()) {
    return it->second;
  }
  return {};
}

} // namespace lib
