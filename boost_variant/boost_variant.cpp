#include <string>
#include <vector>

#include <boost/variant.hpp>
#include <spdlog/spdlog.h>

using Attribute =
    boost::variant<boost::blank, int, float, std::string, std::vector<int>,
                   std::vector<float>, std::vector<std::string>, bool,
                   std::vector<bool>>;

#define DEFINE_SAFE_BOOST_GET(__InputType, __OutputType, __OutputTypePtr,      \
                              __FuncName)                                      \
  template <typename OutputType, typename InputType>                           \
  auto __FuncName(__InputType input, const char *expression, const char *file, \
                  int line) ->                                                 \
      typename std::conditional<std::is_pointer<InputType>::value,             \
                                __OutputTypePtr, __OutputType>::type {         \
    return boost::get<OutputType>(input);                                      \
  }

DEFINE_SAFE_BOOST_GET(InputType &, OutputType &, OutputType *, SafeBoostGet);
DEFINE_SAFE_BOOST_GET(const InputType &, const OutputType &, const OutputType *,
                      SafeBoostGetConst);
DEFINE_SAFE_BOOST_GET(InputType &&, OutputType, OutputType *,
                      SafeBoostGetMutable);

#define BOOST_GET(__TYPE, __VALUE)                                             \
  SafeBoostGet<__TYPE>(__VALUE, #__VALUE, __FILE__, __LINE__)
#define BOOST_GET_CONST(__TYPE, __VALUE)                                       \
  SafeBoostGetConst<__TYPE>(__VALUE, #__VALUE, __FILE__, __LINE__)
#define BOOST_GET_MUTABLE(__TYPE, __VALUE)                                     \
  SafeBoostGetMutable<__TYPE>(__VALUE, #__VALUE, __FILE__, __LINE__)

int main() {
  auto v = std::vector<std::string>();
  v.push_back("abc");
  v.push_back("abc");
  v.push_back("abc");
  v.push_back("abc");

  spdlog::info("{}", &v);
  spdlog::info("{}", &v[0]);
  spdlog::info("{}", &v[2]);

  spdlog::info("{}", "------------");
  Attribute x = v;
  // auto vv = BOOST_GET(std::vector<std::string>, x);
  auto vv = BOOST_GET_MUTABLE(std::vector<std::string>, x);
  spdlog::info("{}", &vv);
  spdlog::info("{}", &vv[0]);
  spdlog::info("{}", &vv[2]);

  return 0;
}
