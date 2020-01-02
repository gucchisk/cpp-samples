#include "hello.h"
#include <string>

struct var_string : boost::static_visitor<std::string> {
  std::string operator()(int i) const {
    return std::to_string(i);
  }
  std::string operator()(std::string str) const {
    return str;
  }
  std::string operator()(char* ch) const {
    return ch;
  }
};

std::string hello(target t) {
  std::string message = boost::apply_visitor(var_string(), t);
  return "hello " + message;
}

std::string hello_cap(cap c) {
  std::string message = boost::apply_visitor(var_string(), c.t);
  return "hello " + message;
}
