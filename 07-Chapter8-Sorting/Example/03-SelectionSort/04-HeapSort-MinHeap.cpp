#include <iostream>
#include <vector>

void PrintArray(std::vector<int>&);

void MinHeapify(std::vector<int>& nums, int heapSize, int i) {
    int smallest = i;
    int left     = i * 2 + 1;
    int right    = i * 2 + 2;

    if (left < heapSize && nums[left] < nums[smallest]) {
        smallest = left;
    }

    if (right < heapSize && nums[right] < nums[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(nums[smallest], nums[i]);
        MinHeapify(nums, heapSize, smallest);
    }
}

void BuildMinHeap(std::vector<int>& nums) {
    int numsSize = nums.size();
    for (int i = numsSize / 2 - 1; i >= 0; i--) {
        MinHeapify(nums, numsSize, i);
    }
}

void HeapSort(std::vector<int>& nums) {
    BuildMinHeap(nums);

    for (int i = nums.size() - 1; i > 0; i--) {
        std::swap(nums[0], nums[i]);
        MinHeapify(nums, i, 0);
    }
}

int main() {
    srand(time(nullptr));
    std::vector<int> nums;

    for (int i = 0; i < 20; i++) {
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
