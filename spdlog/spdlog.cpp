#include <map>
#include <spdlog/fmt/fmt.h>
#include <spdlog/spdlog.h>

int main() {
  std::map<std::string, bool> dict;
  dict.insert({"abc", true});
  dict["abc"] = true;
  spdlog::info("abc is: {}", dict["abc"]);

  dict["abc"] = false;
  spdlog::info("abc is: {}", dict["abc"]);
}
