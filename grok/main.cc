#include <iostream>
#include <grok.h>

int main() {
  std::cout << "grok" << std::endl;
  
  // grok *g = grok_new();
  grok_t *grok = (grok_t *)malloc(sizeof(grok_t));

  grok_init(grok);
  
  // grok_init(g);

  // grok_compile(g, "%{WORD:word}");

  // grok_match_t gm;
  // int match = grok_exec(g, "hello world", &gm);

  // if (match == GROK_OK) {
  //   std::cout << "match" << std::endl;
  // } else {
  //   std::cout << "no match" << std::endl;
  // }
  
  return 0;
}
