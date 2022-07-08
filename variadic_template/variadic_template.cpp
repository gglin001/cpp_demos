#include <glog/logging.h>
#include <ostream>
#include <utility>

void abc(int x) { LOG(ERROR) << x; }
void abc(std::string x) { LOG(ERROR) << x; }
void abc(std::string x, int y) { LOG(ERROR) << x << y; }

template <typename... Params> void f(Params &&...params) {
  abc(std::forward<Params>(params)...);
}

int main() {
  f(10);
  f("x");
  f("x", 10);
}
