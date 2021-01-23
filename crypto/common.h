#include <iostream>
#include <iomanip>

void printBinary(const char *ch, const int32_t len) {
  for (int i = 0; i < len; i++) {
    std::cout << std::hex << std::setfill('0') << std::setw(2)
	      << static_cast<int>(static_cast<unsigned char>(ch[i])) << " ";
  }
  std::cout << std::endl;
}
