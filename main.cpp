#include <iostream>
#include <fstream>
#include "Test.h"
#include "dataStructures/Node.h"
#include "dataStructures/Stack.h"
#include "exceptions/StackException.h"

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

    Node f = Node(2);

    e = Node(ADD, &f, &b);
    test.assertEqual(e.getValue(), 3);


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


Node *treeFromFile(const std::string &filepath) {
    char c;
    std::string digitBuffer;
    bool bBufferEmpty = true;
    Stack stack = Stack();
    std::ifstream inputFile(filepath);
    if (inputFile.is_open()) {
        while (inputFile.get(c)) {
            if (isdigit(c)) {
                bBufferEmpty = false;
                digitBuffer += c;
            } else if (c == ' ') {
                if (!bBufferEmpty) {
                    Node n = Node(stoi(digitBuffer));
                    std::cerr << n.getValue() << "\n";
                    digitBuffer = "";
                    bBufferEmpty = true;
                    stack.push(&n);
                }
            } else {
                eOpType op;
                switch (c) {
                    case '+':
                        std::cerr << "ADD!\n";
                        op = ADD;
                        break;
                    case '-':
                        op = SUB;
                        break;
                    case '/':
                        op = DIV;
                        break;
                    case '*':
                        op = MUL;
                        break;
                    case '~':
                        op = NEG;
                        break;
                    default:
                        throw std::runtime_error("Unknown char in " + filepath + ": " + c + "\n");
                }
                Node *left, *right;
                if (op == NEG) {
                    if (stack.size() == 0) {
                        throw StackException("Stack empty.");
                    }
                    left = stack.pop();
                    right = left;
                } else {
                    if (stack.size() < 2) {
                        throw StackException("Not enough items in stack.");
                    }
                    left = stack.pop();
                    right = stack.pop();
                }

                Node n = Node(op, left, right);
                stack.push(&n);
            }
        }
        if (!bBufferEmpty) {
            Node n = Node(stoi(digitBuffer));
            stack.push(&n);
        }
        return stack.pop();
    } else {
        throw std::runtime_error("No file at " + filepath);
    }
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

    Node *n = treeFromFile("./input.txt");
    std::cout << "Result: " << n->getValue() << "\n";
    return 0;
}
