#include<iostream>
#include "expression.h"
#include "common.h"
#include <regex>
#include "calculator.h"

int main() {
    std::string str;
    double result;

    Calculator calculator;

    std::cout << "enter the expression:\n";
    while (std::getline(std::cin, str)) {
        
        result = calculator.runCalculating(str);
        if (ErrorState::isSuccess()) {
            std::cout << "answer:\n" << result << "\n";
            std::cout << "\n";           
        }
        else {
            std::cout << ErrorState::getErrorMessage()<<"\n\n";
        }
        std::cout << "enter the expression:\n";
    }
    return 0;
}