#include <iostream>
#include <vector>

void PrintArray(std::vector<int>&);

/*
    最大堆：一种完全二叉树，除根节点外，子节点的数值[小于等于]父节点的数值
    最小堆：一种完全二叉树，除根节点外，子节点的数值[大于等于]父节点的数值
 */

// 最大堆调整(Max Heapify)：将堆的末端子节点作调整，使得子节点永远小于父节点
void MaxHeapify(std::vector<int>& nums, int heapSize, int i) {
    int left    = i * 2 + 1; // 父节点的左孩子下标
    int right   = i * 2 + 2; // 父节点的右孩子下标
    int largest = i;         // 将根节点作为最大值节点的下标

    if (left < heapSize && nums[left] > nums[largest]) {
        largest = left;
    }

    if (right < heapSize && nums[right] > nums[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(nums[i], nums[largest]);
        MaxHeapify(nums, heapSize, largest);
    }
}

// 创建最大堆(Build Max Heap)：将堆中的所有数据重新排序
void BuildMaxHeap(std::vector<int>& nums) {
    int numsSize = nums.size();
    for (int i = numsSize / 2 - 1; i >= 0; i--) {
        MaxHeapify(nums, numsSize, i);
    }
}

// 堆排序
void HeapSort(std::vector<int>& nums) {
    int numsSize = nums.size();
    BuildMaxHeap(nums);
    for (int i = numsSize - 1; i > 0; i--) {
        // 将最大值放到已排序部分
        std::swap(nums[i], nums[0]);
        // 缩小范围重新调整最大堆
        MaxHeapify(nums, i, 0);
    }
}

int main() {
    srand(time(nullptr));

    std::vector<int> nums;

    for (int i = 0; i < 15; i++) {
        nums.emplace_back(rand() % 1000 + 1);
    }

    std::cout << "排序前: ";
    PrintArray(nums);
    HeapSort(nums);
    std::cout << "排序后: ";
    PrintArray(nums);

    return 0;
}

void PrintArray(std::vector<int>& nums) {
    for (auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
