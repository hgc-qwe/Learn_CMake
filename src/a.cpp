#include "d.h"
#include <iostream>
using namespace std;

int Jia(int a, int b) {
    auto num = 100;
#ifdef DEBUG
    cout << "自定义宏" << endl;
#endif
    return a + b + num;
}