#include "idclient.h"
#include <iostream>

IdClient::IdClient() {};
Data IdClient::Get(Identifier id) {
  Data d = {"id", boost::get<uint64_t>(id)};
  return d;
}

extern "C" Client* Create() {
  return new IdClient();
}
