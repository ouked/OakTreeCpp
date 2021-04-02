//
// Created by Alex Dawkins on 24/03/2021.
//

#ifndef OAKTREEC___STACKEXCEPTION_H
#define OAKTREEC___STACKEXCEPTION_H

#include <exception>
#include <string>

class StackException : public std::runtime_error {
public:
    explicit StackException(const std::string &msg) : std::runtime_error(msg) {}
};


#endif //OAKTREEC___STACKEXCEPTION_H
