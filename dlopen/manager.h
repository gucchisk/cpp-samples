#include <boost/variant.hpp>
#include <memory>

struct Info {
  std::string group;
  std::string name;
};

typedef boost::variant<Info, uint64_t> Identifier;

struct Data {
  std::string value;
  Identifier id;
};

class Client {
 public:
  virtual Data Get(Identifier id) = 0;
  virtual ~Client() {};
};


class Manager {
 public:
  Manager(std::string libname);
  Data Get(Identifier id);
 private:
  Client* client_;
};
