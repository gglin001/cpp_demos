#include <backward.hpp>
#include <cstdio>
#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <map>

using namespace backward;

void func1() {
  LOG(INFO) << "-> func1";

  // print backtrace
  StackTrace st;
  st.load_here();

  backward::Printer printer;
  printer.address = true;
  printer.object = true;
  printer.print(st, std::cout);

  backward::TraceResolver tr;
  tr.load_stacktrace(st);
  for (size_t i = 0; i < st.size(); ++i) {
    auto trace = tr.resolve(st[i]);
    std::cout << "#" << i << " " << trace.object_filename << " "
              << trace.object_function << " [" << trace.addr << "]"
              << std::endl;
  }
}

void func0() {
  LOG(INFO) << "-> func0";
  func1();
}

int main() { func0(); }
