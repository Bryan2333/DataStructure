#include <cstdint>
#include <iostream>
#include <vector>

void PrintArray(std::vector<int>&);

void CountingSort(std::vector<int>& nums) {
    int numsSize = nums.size();
    if (numsSize <= 1) {
        return;
    }

    // 找到最大值和最小值
    int max = INT32_MIN;
    int min = INT32_MAX;
    for (auto& num : nums) {
        if (num > max) {
            max = num;
        }

        if (num < min) {
            min = num;
        }
    }

    // 准备计数数组，大小为 max - min + 1
    int countSize = max - min + 1;
    std::vector<int> count(max - min + 1, 0);

    // 计数
    for (int i = 0; i < numsSize; i++) {
        count[nums[i] - min]++;
    }

    // 统计计数的累计值
    for (int i = 1; i < countSize; i++) {
        count[i] += count[i - 1];
    }

    // 准备临时数组
    std::vector<int> outputs(numsSize, 0);

    for (int i = 0; i < numsSize; i++) {
        outputs[count[nums[i] - min] - 1] = nums[i];
        count[nums[i] - min]--;
    }

    // 将结果复制回原来的数组
    for (int i = 0; i < numsSize; i++) {
        nums[i] = outputs[i];
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
    CountingSort(nums);
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
