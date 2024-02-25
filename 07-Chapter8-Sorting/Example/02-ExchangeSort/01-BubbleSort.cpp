// 冒泡排序
#include <iostream>
#include <vector>

void PrintArray(std::vector<int>&);

void BubbleSort(std::vector<int>& nums) {
    // 用于标记本次循环有没有交换
    bool ifSwap = false;

    int numsSize = nums.size();
    for (int i = 0; i < numsSize; i++) {
        ifSwap = 0;
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                ifSwap = true;
            }
        }
        if (ifSwap == false) {
            break;
        }
    }
}

int main() {
    srand((unsigned int)time(nullptr));

    std::vector<int> nums;

    for (int i = 0; i < 10; i++) {
        nums.emplace_back(rand() % 100 + 1);
    }

    std::cout << "排序前: ";
    PrintArray(nums);
    BubbleSort(nums);
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
