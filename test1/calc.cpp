#include <iostream>
#include "calc.h"

int main(int argc, char **argv) {
    int a = 20;
    int b = 10;

    std::cout << "========== 计算器演示 ==========\n";
    std::cout << a << " + " << b << " = " << add(a, b) << "\n";
    std::cout << a << " - " << b << " = " << subtract(a, b) << "\n";
    std::cout << a << " * " << b << " = " << multiply(a, b) << "\n";
    std::cout << a << " / " << b << " = " << divide(a, b) << "\n";

    return 0;
}
