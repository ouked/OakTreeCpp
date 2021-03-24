#include <iostream>
#include "Test.h"
#include "datastructures/Node.h"
#include "datastructures/Stack.h"

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

void testStack(Test &test) {
    Stack s = Stack();
    Node n = Node(7);
    s.push(&n);

    test.assertEqual(s.size(), 1);
    test.assertEqual(s.peek()->getValue(), 7);
    test.assertEqual(s.pop()->getValue(), 7);
    test.assertEqual(s.size(), 0);

    Node m = Node(10);
    s.push(&n);
    s.push(&m);
    test.assertEqual(s.size(), 2);
    test.assertEqual(s.peek()->getValue(), 10);
    test.assertEqual(s.pop()->getValue(), 10);
    test.assertEqual(s.pop()->getValue(), 7);


}

void runAllTests() {
    std::cout << "Running tests..." << std::endl;
    Test test = Test();
    testNode(test);
    testStack(test);
    std::cout << test.getResults();
}

int main() {
    runAllTests();
    return 0;
}
