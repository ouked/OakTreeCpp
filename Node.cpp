//
// Created by Alex Dawkins on 17/03/2021.
//

#include "Node.h"
#include "TreeException.h"

int Node::getValue() const {
    if (!this->isSafe()) {
        throw TreeException("Unsafe node.");
    }

    Node *leftNode = this->left;
    Node *rightNode = this->right;

    switch (this->type){
        case NUM:
            return this->data;
        case ADD:
            return leftNode->getValue() + rightNode->getValue();
        case SUB:
            return leftNode->getValue() - rightNode->getValue();
        case MUL:
            return leftNode->getValue() * rightNode->getValue();
        case DIV:
            return leftNode->getValue() / rightNode->getValue();
        case NEG:
            return leftNode->getValue() * -1;
        case ERR:
            throw TreeException("Error node in tree.");
        default:
            throw std::runtime_error("Node type not implemented.");
    }
}

Node *Node::getLeft() const {
    return left;
}

void Node::setLeft(Node *left) {
    Node::left = left;
}

Node *Node::getRight() const {
    return right;
}

void Node::setRight(Node *right) {
    Node::right = right;
}

bool Node::isSafe() const {
    return !(this->type != NUM &&
             (this->left == nullptr || this->right == nullptr || this->left->type == ERR || this->right->type == ERR)
    );
}

Node::Node(opType type, Node *left, Node *right) : type(type), data(0), left(left), right(right) {}

Node::Node(int data) : type(NUM), data(data), left(nullptr), right(nullptr) {}

