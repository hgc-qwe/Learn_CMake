//
// Created by 19327 on 2026/01/25/星期日.
//
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

// ==================== 选择排序 ====================
// 思想：每次从未排序区间选择最小（或最大）元素，放到已排序区间的末尾
// 时间复杂度：O(n²)（无论最好最坏情况）
// 空间复杂度：O(1)
// 稳定性：不稳定（交换可能改变相同元素的相对顺序）
void selectionSort(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;  // 假设当前位置最小

        // 在未排序区间找最小值下标
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // 将最小值交换到已排序区间的末尾
        if (minIdx != i) {
            std::swap(arr[i], arr[minIdx]);
        }
    }
}

// 选择排序（带详细打印版本）
void selectionSortWithPrint(std::vector<int> &arr) {
    int n = arr.size();
    std::cout << "【选择排序过程】\n";
    std::cout << "初始数组: ";
    for (int x: arr) std::cout << x << " ";
    std::cout << "\n\n";

    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        std::cout << "第" << i + 1 << "轮，选择最小值 " << arr[minIdx]
                  << " (下标" << minIdx << ")，与位置" << i << "交换:\n";

        if (minIdx != i) {
            std::swap(arr[i], arr[minIdx]);
        }

        std::cout << "  结果: ";
        for (int x: arr) std::cout << x << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}