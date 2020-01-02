#include <boost/variant.hpp>

typedef boost::variant<int, std::string, char*> target;

struct cap {
  target t;
};

std::string hello(target t);
std::string hello_cap(cap c);
