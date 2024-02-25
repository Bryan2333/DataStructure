// 直接插入排序(顺序存储结构)
#include <iostream>
#include <vector>

void StraightInsertionSort(std::vector<int>& nums) {
    int numsSize = nums.size();
    for (int i = 0; i < numsSize; i++) {
        // 使用tmp来保存要当前元素的key值
        int tmp = nums[i];
        int j   = i - 1;

        // 将当前元素和已排序的部分进行比较，找到插入的位置
        while (j >= 0 && nums[j] > tmp) {
            nums[j + 1] = nums[j];
            j--;
        }
        // 将元素插入到对应的位置
        nums[j + 1] = tmp;
    }
}

void PrintArray(std::vector<int>& nums) {
    for (auto& val : nums) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(void) {
    srand(time(nullptr));

    std::vector<int> nums;

    for (int i = 0; i < 10; i++) {
        nums.emplace_back(rand() % 100 + 1);
    }

    std::cout << "排序前: ";
    PrintArray(nums);
    StraightInsertionSort(nums);
    std::cout << "排序后: ";
    PrintArray(nums);

    return 0;
}
