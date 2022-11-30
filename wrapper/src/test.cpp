#include "test.h"

int TaskTest::Test(int a, int b) {
    std::cout << "Test:\n";
    std::cout << "arguments: " << a <<" * "<< b <<" = ";
    return a*b;
}
