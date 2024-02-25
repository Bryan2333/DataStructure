// 简单选择排序(顺序存储结构)
#include <iostream>
#include <vector>

void PrintArray(std::vector<int>&);

void SimpleSelectionSort(std::vector<int>& nums) {
    int numsSize = nums.size();
    for (int i = 0; i < numsSize; i++) {
        int minPos = i;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[minPos]) {
                minPos = j;
            }
        }
        if (minPos != i) {
            std::swap(nums[i], nums[minPos]);
        }
    }
}

int main() {
    srand(time(nullptr));

    std::vector<int> nums;

    for (int i = 0; i < 10; i++) {
        nums.emplace_back(rand() % 100 + 1);
    }

    std::cout << "排序前: ";
    PrintArray(nums);
    SimpleSelectionSort(nums);
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
