#include "lib.h"

namespace lib {

void func_a(int a) { std::cout << "a is " << a << "\n"; }

REGISTER(func_a, func_a);

} // namespace lib
