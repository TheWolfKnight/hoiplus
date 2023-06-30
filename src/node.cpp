
#include <memory>
#include <string>
#include <format>
#include <cstdlib>

#ifndef _PARAMETER_DEFINITION
#include "./parameter.cpp"
#endif // _PARAMETER_DEFINITION

#ifndef _NODE_DEFINITION
#define _NODE_DEFINITION

enum NodeType {
  NO_UNDEFINED = 0,

  // FOCUS HANDLING
  NO_CREATE_FOCUS,
  NO_CHANGE_FOCUS_POSTION,
  NO_ADD_FOCUS_PARENT,
  NO_ADD_MUT_FOCUS_PARENT,
  NO_SET_FOCUS_COST,
  // END FOCUS HANDLING

};

class Node {
private:
  std::string* file_path;
  std::vector<std::unique_ptr<Parameter>> params;
  std::vector<std::unique_ptr<Node>> sub_nodes;
  std::vector<ParamType> requred_types;
public:
  NodeType type;
  unsigned int row, col;

  Node(NodeType type) {
    this->type = type;
    requred_types.push_back(PT_BOOL);
  }

  bool push_param(std::unique_ptr<Parameter> p) {
    if (this->requred_types.size() == this->params.size()) {
      std::string msg = std::format("Syntax Error: Parameter overflow, the function needs {} parameters", this->requred_types.size());
      write_error(msg.c_str(), p->file_path->c_str(), p->row, p->col);
      return false;
    }
    this->params.push_back(std::move(p));
    return true;
  }

  std::string to_string() {
    return "Not Implemented";
  }

  std::string type_to_string() {
    // switch (this->type) {
    //   default:
    //     write_error()
    // }
    return "not implemented";
  }

  // ~Node() {
  //   free(this->params);
  // }
};

#endif // _NODE_DEFINITION
