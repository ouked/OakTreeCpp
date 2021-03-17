#include <iostream>
#include "Test.h"
#include "Node.h"

void testNode(Test &test) {
    Node a = Node(7);
    test.assertEqual(a.getValue(), 7);

    Node b = Node(1);

    Node c = Node(SUB, &a, &b);
    test.assertEqual(c.getValue(), 6);

    c = Node(DIV, &a, &b);
    test.assertEqual(c.getValue(), 7);

    c = Node(MUL, &a, &b);
    test.assertEqual(c.getValue(), 7);

    c = Node(NEG, &a, &b);
    test.assertEqual(c.getValue(), -7);

    c = Node(ADD, &a, &b);
    test.assertEqual(c.getValue(), 8);

    Node d = Node(10);
    Node e = Node(MUL, &d, &a);
    test.assertEqual(e.getValue(), 70);

//    todo: add support for floating point numbers
//    e = Node(DIV, &d, &b);
//    test.assertEqual(e.getValue(), 70);
    e = Node(SUB, &d, &b);
    test.assertEqual(e.getValue(), 9);

    e = Node(ADD, &d, &b);
    test.assertEqual(e.getValue(), 11);

}

void runAllTests() {
    Test test = Test();
    testNode(test);
    std::cout << test.getResults();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    runAllTests();
    return 0;
}
