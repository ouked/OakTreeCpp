//
// Created by Alex Dawkins on 17/03/2021.
//

#include "testNode.h"
int counter;
int failed;

/// Asserts a == b. Prints to cerr and increments failed if this isn't the case.
/// \param a First value
/// \param b Second value
/// \return 1 if equal, 0 if not
int assertEquals(int a, int b){
    ++counter;
    if (a != b) {
        ++failed;
        std::cerr << "assertEquals: " << a << "!=" << b;
        return 0;
    }
    return 1;
}

/// Test node class
void testNode(){
    std::cout << "Running tests for nodes...\n";
    failed = 0;
    counter = 0;
}