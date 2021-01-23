#include "infoclient.h"

InfoClient::InfoClient() {};
Data InfoClient::Get(Identifier id) {
  Data d = {"info", boost::get<Info>(id)};
  return d;
}

extern "C" Client* Create() {
  return new InfoClient();
}
