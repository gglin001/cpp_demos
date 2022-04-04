#include "lib.h"

void func_a(int a) { std::cout << "a is " << a << "\n"; }

REGISTER(func_a, func_a);
