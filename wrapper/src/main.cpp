#include <iostream>
#include <string>

#include "wrapper_engine.h"
#include "test.h"

int main() {
    // ����������� ������������ ������� ������ ������������ ��������� 
    // ��� ����-�����
    TaskTest taskTest;
    Wrapper<int> wrapper(&taskTest, &TaskTest::Test, { {"arg1", 0}, {"arg2", 0} });

    Engine engine;
    engine.register_�ommand<int>(&wrapper, "command1");
    std::cout << engine.execute<int>("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;
}