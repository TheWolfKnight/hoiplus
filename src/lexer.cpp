
#include <memory>
#include <string>
#include <format>
#include <cstdlib>
#include <algorithm>

#ifndef _NODE_DEFINITION
#include "./node.cpp"
#endif // _NODE_DEFINITION

#ifndef _PARAMETER_DEFINITION
#include "./parameter.cpp"
#endif // _PARAMETER_DEFINITION

#ifndef _GLOBAL_DEFINITION
#include "./global.hpp"
#endif // _GLOBAL_DEFINITION

#ifndef _LEXER_DEFINITION
#define _LEXER_DEFINITION

class Lexer {
private:
  std::string *file_path;

  static int is_digit_or_coma(int c) {
    return std::isdigit(c) || c == '.';
  }

  bool is_number(const std::string &s) {
    size_t s_len = s.length();

    if (s_len == 0)
      return false;

    std::string n;
    if (s.at(0) == '-') n = s.substr(1, s_len-1);
    else n = s;
    return !n.empty() && std::all_of(n.begin(), n.end(), Lexer::is_digit_or_coma);
  }

  bool is_valid_string(const std::string &s) {
    size_t s_len = s.length();

    if (s_len == 0 || s.at(0) != '"' || s.at(s_len-1) != '"') {
      return false;
    }

    // removes the " from both ends
    std::string n = s.substr(1, s_len-2);

    for (char ch : n) {
      if (ch == '"') {
        write_error("Syntax Error: Malformed string", this->file_path->c_str(), this->row, this->col);
        return false;
      }
    }

    return true;
  }

public:
  unsigned int row, col;

  void set_pos(std::string *file_path, unsigned int row, unsigned int col) {
    this->file_path = file_path;
    this->row = row;
    this->col = col;
  }

  std::unique_ptr<Node> get_node(std::string node_text) {
    std::unique_ptr<Node> r(new Node(NO_CHANGE_NAMESPACE));
    return r;
  }

  std::unique_ptr<Parameter> get_param(std::string param_text) {
    std::unique_ptr<Parameter> r(new Parameter(param_text));
    ParamType type = PT_UNDEFINED;

    if (param_text == "true" || param_text == "false")
      type = PT_BOOL;
    else if (this->is_number(param_text))
      type = PT_NUMBER;
    else if (this->is_valid_string(param_text))
      type = PT_STRING;
    else {
      std::string msg = std::format("Syntax Error: Could not finde the type of: {}", param_text);
      write_error(msg.c_str(), this->file_path->c_str(), this->row, this->col);
    }

    r->type = type;
    return r;
  }
};

#endif // _LEXER_DEFINITION
