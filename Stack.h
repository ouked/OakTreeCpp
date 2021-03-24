//
// Created by Alex Dawkins on 24/03/2021.
//

#ifndef OAKTREEC___STACK_H
#define OAKTREEC___STACK_H


#include <stdexcept>
#include "Node.h"

#define MAX_SIZE 64

class Stack {

private:
    int pointer = 0;
    Node *data[MAX_SIZE] = {};

public:
    [[nodiscard]] int size() const;

    [[nodiscard]] Node *peek() const;

    Node *pop();

    void push(Node *n);
};


#endif //OAKTREEC___STACK_H
