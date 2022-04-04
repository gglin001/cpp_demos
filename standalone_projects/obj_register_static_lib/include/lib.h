#pragma once

#include <functional>
#include <iostream>
#include <unordered_map>

#define UNUSED __attribute__((unused))

namespace lib {

#define STATIC_ASSERT_GLOBAL_NAMESPACE(uniq_name, msg)                         \
  struct __test_global_namespace_##uniq_name##__ {};                           \
  static_assert(std::is_same<::__test_global_namespace_##uniq_name##__,        \
                             __test_global_namespace_##uniq_name##__>::value,  \
                msg)

#define REGISTER(__name, func)                                                 \
  STATIC_ASSERT_GLOBAL_NAMESPACE(                                              \
      __reg_function__##op_type,                                               \
      "REGISTER must be called in global namespace");                          \
  struct __Register_##__name {                                                 \
    __Register_##__name() {                                                    \
      std::cout << "__register " << #__name << std::endl;                      \
      lib::RegisterFunction(#__name, func);                                    \
    }                                                                          \
    int Touch() const { return 0; }                                            \
  };                                                                           \
  static __Register_##__name __Register_instance##__name;                      \
  int TouchRegister_##__name() { return __Register_instance##__name.Touch(); }

#define USE(__name)                                                            \
  STATIC_ASSERT_GLOBAL_NAMESPACE(__use_function__##op_type,                    \
                                 "USE must be called in global namespace");    \
  extern int TouchRegister_##__name();                                         \
  UNUSED static int use_handler__itself_##__name##_ = TouchRegister_##__name()

using Function = std::function<void(int)>;

bool RegisterFunction(const std::string &, const Function &);

Function GetFunction(const std::string &);

class NoUse {
public:
  NoUse();
};

} // namespace lib
