//
// Created by Alex Dawkins on 17/03/2021.
//

#ifndef OAKTREEC___NODE_H
#define OAKTREEC___NODE_H

#include <string>

enum eOpType {
    ADD, SUB, MUL, DIV, NEG, NUM, ERR
};

class Node {

    enum eOpType type;
    int data;
    Node *left{};
    Node *right{};

public:
    Node(eOpType type, Node *left, Node *right);

    explicit Node(int data);

    [[nodiscard]] int getValue() const;

    [[nodiscard]] bool isSafe() const;

    [[nodiscard]] Node *getLeft() const;

    void setLeft(Node *left);

    [[nodiscard]] Node *getRight() const;

    void setRight(Node *right);

    std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> toString() const;
};


#endif //OAKTREEC___NODE_H
