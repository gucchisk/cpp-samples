#include "manager.h"

class InfoClient : public Client {
 public:
  InfoClient();
  Data Get(Identifier id);
};
