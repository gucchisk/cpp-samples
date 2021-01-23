#include "manager.h"
#include <iostream>

int main() {
  Manager id("libidclient.dylib");
  Data d = id.Get(2);
  std::cout << "id value: " << d.value << std::endl;

  Manager info("libinfoclient.dylib");
  Info i = {"group", "name"};
  d = info.Get(i);
  std::cout << "info value: " << d.value << std::endl;
  return 0;
}
