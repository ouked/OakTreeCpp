//
// Created by Alex Dawkins on 24/03/2021.
//

#include <iostream>
#include "Stack.h"
#include "../exceptions/StackException.h"


int Stack::size() const {
    return this->pointer;
}

Node *Stack::peek() const {
    return data[this->pointer];
}

Node *Stack::pop() {
    if (this->pointer == 0) {
        throw StackException("Stack empty.");
    }
    return data[--this->pointer];
}

void Stack::push(Node *n) {
    if (this->pointer == MAX_SIZE) {
        throw StackException("Stack size limit reached.");
    }
    data[this->pointer++] = n;
}