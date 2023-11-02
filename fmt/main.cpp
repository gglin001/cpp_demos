#include <fmt/format.h>
#include <glog/logging.h>

int main() {
  int a = 100;

  LOG(ERROR) << fmt::format("a= {} \n", a);
}
