cmake_minimum_required(VERSION 3.15)
project(OakTreeC__)

set(CMAKE_CXX_STANDARD 17)

add_executable(OakTreeC__ main.cpp dataStructures/Node.cpp dataStructures/Node.h dataStructures/Stack.cpp dataStructures/Stack.h exceptions/TreeException.cpp exceptions/TreeException.h Test.cpp Test.h dataStructures/Stack.cpp dataStructures/Stack.h)
