#include <iostream>
#include <vector>

void PrintArray(std::vector<int>&);

void CocktailSort(std::vector<int>& nums) {
    int numsSize = nums.size();
    if (numsSize <= 1) {
        return;
    }

    int left    = 0;
    int right   = numsSize - 1;
    bool ifSwap = true;

    while (ifSwap) {
        ifSwap = false;
        for (int i = left; i < right; i++) {
            if (nums[i] > nums[i + 1]) {
                std::swap(nums[i], nums[i + 1]);
                ifSwap = true;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (nums[i] < nums[i - 1]) {
                std::swap(nums[i], nums[i - 1]);
                ifSwap = true;
            }
        }
        left++;
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
    CocktailSort(nums);
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
