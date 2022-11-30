#include <iostream>
#include <string>

#include "wrapper_engine.h"
#include "test.h"

int main() {
    // реализовать инкапсуляцию методов класса произвольной сигнатуры 
    // Код юнит-теста
    TaskTest taskTest;
    Wrapper<int> wrapper(&taskTest, &TaskTest::Test, { {"arg1", 0}, {"arg2", 0} });

    Engine engine;
    engine.register_сommand<int>(&wrapper, "command1");
    std::cout << engine.execute<int>("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;
}