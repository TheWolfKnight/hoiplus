
#include <string>
#include <vector>
#include <fstream>

#include <iostream>

#ifndef _PARSER_DEFINITION
#define _PARSER_DEFINITION

#include "./ast.cpp"
#include "./node.cpp"
#include "./parameter.cpp"
#include "./lexer.cpp"

class Parser {
private:
  std::vector<std::string> lines;

public:
  Parser(std::string file_path) {
    std::ifstream file(file_path);
    std::string line;

    while (getline(file, line))
      lines.push_back(line);
  }

  AST* generate_tree() {
    AST* r = new AST();
    for (std::string line : this->lines) {
    }
    return r;
  }
};

#endif // _PARSER_DEFINITION
