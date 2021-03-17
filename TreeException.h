//
// Created by Alex Dawkins on 17/03/2021.
//

#ifndef OAKTREEC___TREEEXCEPTION_H
#define OAKTREEC___TREEEXCEPTION_H


#include <exception>
#include <string>

class TreeException : public std::runtime_error {
public:
    explicit TreeException(const std::string& msg) : std::runtime_error(msg) {}
};


#endif //OAKTREEC___TREEEXCEPTION_H
