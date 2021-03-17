//
// Created by Alex Dawkins on 17/03/2021.
//

#ifndef OAKTREEC___NODE_H
#define OAKTREEC___NODE_H

enum opType{ADD, SUB, MUL, DIV, NEG, NUM, ERR};

class Node {
    enum opType type;
    int data;
    Node *left{};
    Node *right{};

public:
    Node(opType type, int data, Node *left, Node *right);

    int getValue() const;
    bool isSafe() const ;

    Node *getLeft() const;

    void setLeft(Node *left);

    Node *getRight() const;

    void setRight(Node *right);
};


#endif //OAKTREEC___NODE_H
