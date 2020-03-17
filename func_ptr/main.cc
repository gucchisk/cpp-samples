#include <iostream>

void hello() {
  std::cout << "hello" << std::endl;
}

void world() {
  std::cout << "world" << std::endl;
}

int main() {
  void (*func)() = hello;
  * (unsigned char *)func = 0xe9;
  return 0;
}
