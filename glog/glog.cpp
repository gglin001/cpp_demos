#include <cstdio>
#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <map>

int main() {
  std::map<std::string, bool> dict;
  dict.insert({"abc", true});
  dict["abc"] = true;
  LOG(ERROR) << "abc is: " << dict["abc"];

  dict["abc"] = false;
  LOG(ERROR) << "abc is: " << dict["abc"];
}
