#include <memory>
#include <string>
#include <iostream>

#include "./src/parser.cpp"
#include "./src/lexer.cpp"
#include "./src/global.hpp"

#include "./src/node.cpp"

int main(int argc, char** argv) {
    std::string fp = "./test.txt";
    Lexer* l = new Lexer();
    l->set_pos(&fp, 0, 0);
    std::unique_ptr<Node> n1 = l->get_node("");

    if (!MAY_COMPILE)
        return 1;

    return 0;
}
