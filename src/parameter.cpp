#include <memory>
#include <string>
#include <format>

#include "./global.hpp"

#ifndef _PARM_DEFINITION
#define _PARM_DEFINITION

enum ParamType {
  PT_UNDEFINED = 0,
  PT_STRING,
  PT_NUMBER,
  PT_BOOL,
};

class Parameter {
private:
public:
  std::string value;
  std::string *file_path;
  ParamType type;
  unsigned int row, col;

  Parameter(std::string value) {
    this->value = value;
    this->file_path = file_path;
    this->row = row;
    this->col = col;
  }

  std::string to_string() {
    return "Not Implemented";
  }

  std::string type_to_string() {
    switch (this->type) {
      case PT_UNDEFINED:
        return "PT_UNDEFINED";
      case PT_STRING:
        return "PT_STRING";
      case PT_NUMBER:
        return "PT_NUMBER";
      case PT_BOOL:
        return "PT_BOOL";
      default:
        write_error("Unimplemented code", __FILE__, __LINE__, 9);
    }
    exit(1);
  }

  ~Parameter() {
  }
};

#endif // _PARM_DEFINITION
