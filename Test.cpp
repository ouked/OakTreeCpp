//
// Created by Alex Dawkins on 17/03/2021.
//

#include <iostream>
#include "Test.h"

void Test::setup() {
    ++this->nTests;
}

void Test::teardown(int result, const std::string &reason) {
    std::string msg = "Test " + std::to_string(this->nTests) + " ";
    if (result) {
        std::cout << msg << "passed." << reason << "\n";
    } else {
        ++this->nFailedTests;
        std::cerr << msg << "failed." << reason << "\n";
    }
}

int Test::assertEqual(int a, int b) {
    this->setup();
    std::string reason;
    int result = 1;
    if (a != b) {
        reason = "assertEqual: " + std::to_string(a) + "!=" + std::to_string(b);
        result = 0;
    }
    this->teardown(result, reason);
}


int Test::assertNotEqual(int a, int b) {
    this->setup();
    std::string reason;
    int result = 1;
    if (a == b) {
        reason = "assertEqual: " + std::to_string(a) + "==" + std::to_string(b);
        result = 0;
    }
    this->teardown(result, reason);
}

std::string Test::getResults() const {
    int nPassed = this->getNPassedTests();
    std::string result = std::to_string(nPassed) + "/" + std::to_string(this->nTests) + " tests passed.";
    if (nPassed == this->nTests) {
        result = "Success! " + result;
    }

    return result;
}


void Test::reset() {
    this->nFailedTests = 0;
    this->nTests = 0;
}

int Test::getNFailedTests() const {
    return nFailedTests;
}

int Test::getNTests() const {
    return nTests;
}

int Test::getNPassedTests() const {
    return (this->nTests - this->nFailedTests);
}



