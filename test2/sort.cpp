//
// Created by 19327 on 2026/01/25/星期日.
//
#include "sort.h"
#include "vector"
#include "string"
#include "iostream"
#include "chrono"
#include <algorithm>

void printArray(const std::vector<int> &arr, const std::string &label) {
    std::cout << label << ": ";
    for (int x: arr) std::cout << x << " ";
    std::cout << "\n";
}

int main(int argc, char **argv) {
    // 测试数据
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> arr3 = {5, 2, 4, 6, 1, 3};
    std::vector<int> arr4 = {5, 2, 4, 6, 1, 3};

    std::cout << "========== 排序算法演示 ==========\n\n";

    // ========== 插入排序演示 ==========
    std::cout << ">>> 插入排序 <<<\n";
    printArray(arr1, "排序前");
    insertionSort(arr1);
    printArray(arr1, "排序后");
    std::cout << "\n";

    // 详细过程演示
    insertionSortWithPrint(arr3);

    // ========== 选择排序演示 ==========
    std::cout << ">>> 选择排序 <<<\n";
    printArray(arr2, "排序前");
    selectionSort(arr2);
    printArray(arr2, "排序后");
    std::cout << "\n";

    // 详细过程演示
    selectionSortWithPrint(arr4);

    // ========== 性能对比测试 ==========
    std::cout << "========== 性能对比（大数组） ==========\n";

    const int TEST_SIZE = 10000;
    std::vector<int> bigArr1(TEST_SIZE), bigArr2(TEST_SIZE);

    // 生成随机数据
    for (int i = 0; i < TEST_SIZE; ++i) {
        bigArr1[i] = bigArr2[i] = rand() % 100000;
    }

    // 插入排序计时
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(bigArr1);
    auto end = std::chrono::high_resolution_clock::now();
    auto insertTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // 选择排序计时
    start = std::chrono::high_resolution_clock::now();
    selectionSort(bigArr2);
    end = std::chrono::high_resolution_clock::now();
    auto selectTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "数组大小: " << TEST_SIZE << "\n";
    std::cout << "插入排序耗时: " << insertTime << " ms\n";
    std::cout << "选择排序耗时: " << selectTime << " ms\n";

    // 验证排序正确性
    bool sorted1 = std::is_sorted(bigArr1.begin(), bigArr1.end());
    bool sorted2 = std::is_sorted(bigArr2.begin(), bigArr2.end());
    std::cout << "插入排序结果正确: " << (sorted1 ? "是" : "否") << "\n";
    std::cout << "选择排序结果正确: " << (sorted2 ? "是" : "否") << "\n";

    return 0;
}
