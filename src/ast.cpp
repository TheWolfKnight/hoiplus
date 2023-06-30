
#include <string>
#include <format>
#include <cstdlib>

#ifndef _AST_DEFINITION
#define _AST_DEFINITION

#include "node.cpp"

class AST {
private:
public:
  std::string *file_name;
  size_t node_count;
  Node* nodes;

  std::string to_string() {
    return "Not implemented";
  }
};

#endif // _AST_DEFINITION
