#include <iostream>
#include <vector>

void PrintArray(std::vector<int>&);

void GnomeSort(std::vector<int>& nums) {
    int pos      = 0;
    int numsSize = nums.size();
    while (pos < numsSize) {
        if (pos == 0 || nums[pos] >= nums[pos - 1])
            pos++;
        else {
            std::swap(nums[pos], nums[pos - 1]);
            pos--;
        }
    }
}

int main() {
    srand(time(nullptr));
    std::vector<int> nums;

    for (int i = 0; i < 10; i++) {
        nums.emplace_back(rand() % 100 + 1);
    }

    printf("排序前: ");
    PrintArray(nums);
    GnomeSort(nums);
    printf("排序后: ");
    PrintArray(nums);
    return 0;
}

void PrintArray(std::vector<int>& nums) {
    for (auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
