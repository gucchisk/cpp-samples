#include "manager.h"
#include <dlfcn.h>
#include <iostream>

Manager::Manager(std::string libname) {
  void* handle = dlopen(libname.c_str(), RTLD_LAZY);
  const char *dlopen_error = dlerror();
  if (dlopen_error) {
    std::cout << dlopen_error << std::endl;
  }
  Client* (*create)();
  create = (Client* (*)())dlsym(handle, "Create");
  const char *dlsym_error = dlerror();
  if (dlsym_error) {
    std::cout << dlsym_error << std::endl;
  }
  client_ = create();
}

Data Manager::Get(Identifier id) {
  return client_->Get(id);
}
