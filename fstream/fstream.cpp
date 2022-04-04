#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>

int main() {
  std::fstream fs;
  fs.open("LICENSE", std::ifstream::binary | std::ios::in);

  std::fstream new_fs("LICENSE.dat", std::ifstream::binary | std::ios::out);

  fs.seekg(0, std::ios::end);
  int cache_len = fs.tellg();
  fs.seekg(0, std::ios::beg);

  char *cache_buff = new char[cache_len];
  memset(cache_buff, 0, cache_len);
  fs.read(cache_buff, cache_len);

  new_fs.write(cache_buff, cache_len);

  new_fs.close();
  fs.close();
}
