#include "manager.h"

class IdClient : public Client {
 public:
  IdClient();
  Data Get(Identifier id);
};
