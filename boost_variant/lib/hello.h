#include <boost/variant.hpp>

using target = boost::variant<int, std::string, char*>;

struct cap {
  target t;
};

std::string hello(target t);
std::string hello_cap(cap c);
