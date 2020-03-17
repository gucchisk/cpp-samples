#include <iostream>
#include <iomanip>
#include <cstring>

#include <sys/mman.h>
#include <stdint.h>

class Unprotect
{
public:
  Unprotect(void *location, size_t count)
  : origFunc((intptr_t)location & (~0xFFF))
  , byteCount(count + ((intptr_t)location - origFunc))
  {
        mprotect((void *)origFunc, this->byteCount, PROT_READ|PROT_WRITE|PROT_EXEC);
  };
  ~Unprotect()
  {
        mprotect((void *)origFunc, byteCount, PROT_READ|PROT_EXEC);
  }
private:
  intptr_t origFunc;
  int byteCount;
};

template <typename T, typename U>
T horrible_cast(U u)
{
        union { T t; U u; } un;
        un.u = u;
        return un.t;
}

void hello() {
  std::cout << "hello" << std::endl;
}

void world() {
  std::cout << "world" << std::endl;
}

int main() {
  void (*func)() = hello;
  // void* func = horrible_cast<void *>(hello);
  // Unprotect _allow_write((void*)func, 32);
  // * (unsigned char *)func = 0xe9;

  char *ch = "hello";
  mprotect((void *)ch, 1, PROT_WRITE|PROT_READ);
  *ch = '!';
  std::cout << ch << std::endl;
  
  return 0;
}
