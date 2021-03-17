//
// Created by Alex Dawkins on 17/03/2021.
//

#ifndef OAKTREEC___TEST_H
#define OAKTREEC___TEST_H


class Test {
public:
    Test() : nTests(0), nFailedTests(0) {};

    /// Asserts a == b. Prints to cerr and increments failed if this isn't the case.
    /// \param a First value
    /// \param b Second value
    /// \return 1 if equal, 0 if not
    int assertEqual(int a, int b);

    /// Asserts a != b. Prints to cerr and increments failed if this isn't the case.
    /// \param a First value
    /// \param b Second value
    /// \return 0 if equal, 1 if not
    int assertNotEqual(int a, int b);

    /// Resets test counters to 0.
    void reset();

    /// Generate a summarising string.
    [[nodiscard]] std::string getResults() const;

    /// Gets the number of failed tests
    [[nodiscard]] int getNFailedTests() const;

    /// Gets the total number of tests
    [[nodiscard]] int getNTests() const;

    /// Gets the number of passed tests
    [[nodiscard]] int getNPassedTests() const;

private:
    /// Total number of tests
    int nTests;
    /// Number of failed tests
    int nFailedTests;

    /// Setup for single test
    void setup();

    /// Teardown for single test
    void teardown(int result, const std::string &reason = "");
};


#endif //OAKTREEC___TEST_H
