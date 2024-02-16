#include <spdlog/spdlog.h>
#include <utility>

void abc(int x) { spdlog::info(x); }
void abc(std::string x) { spdlog::info(x); }
void abc(std::string x, int y) { spdlog::info("{} {}", x, y); }

template <typename... Params> void f(Params &&...params) {
  abc(std::forward<Params>(params)...);
}

int main() {
  f(10);
  f("x");
  f("x", 10);
}
