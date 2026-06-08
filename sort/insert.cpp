//
// Created by 19327 on 2026/01/25/星期日.
//
#include <iostream>
#include <vector>
#include "calc.h"

// ==================== 插入排序 ====================
// 思想：每次将一个待排序的元素，按其关键字大小插入到前面已排好序的子序列中
// 时间复杂度：O(n²)，最好情况O(n)（已有序）
// 空间复杂度：O(1)
// 稳定性：稳定
void insertionSort(std::vector<int> &arr) {
    auto number = add(100, 2);
    printf("insertionSort.number:%d \n", number);
    int n = arr.size();
    // 从第二个元素开始（第一个元素默认已排序）
    for (int i = 1; i < n; ++i) {
        int key = arr[i];      // 当前要插入的元素
        int j = i - 1;

        // 将比 key 大的元素向后移动一位
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        // 找到 key 的正确位置
        arr[j + 1] = key;
    }
}

// 插入排序（带详细打印版本，方便理解过程）
void insertionSortWithPrint(std::vector<int> &arr) {
    int n = arr.size();
    std::cout << "【插入排序过程】\n";
    std::cout << "初始数组: ";
    for (int x: arr) std::cout << x << " ";
    std::cout << "\n\n";

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        std::cout << "第" << i << "轮，插入元素 " << key << ":\n";

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;

        std::cout << "  结果: ";
        for (int x: arr) std::cout << x << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}