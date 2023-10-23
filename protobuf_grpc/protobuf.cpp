#include <iostream>

#include "message.pb.h"

int main(int argc, char const *argv[]) {
  message::Message m;
  m.mutable_idx()->Add(100);

  std::cout << "m.idx: " << m.idx().at(0) << "\n";

  return 0;
}
