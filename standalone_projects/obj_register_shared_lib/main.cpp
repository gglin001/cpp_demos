#include "lib.h"
#include <iostream>

int main(int argc, char *argv[]) {
  auto func_a = lib::GetFunction("func_a");
  std::cout << "running func_a(100)" << std::endl;
  func_a(100);

  return 0;
}
