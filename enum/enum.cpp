#include <iostream>

using namespace std;

enum class EnumType {
  Sum = 0,
  Mean,
  Nop,
  /// The number of EnumType values
  N
};

void func(const EnumType reduction = EnumType::Mean) {
  std::cout << "EnumType: " << static_cast<int>(reduction) << std::endl;
}

int main() {
  int tt = 0;
  auto x = static_cast<EnumType>(tt);
  func(x);
}