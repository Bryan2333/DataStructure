// 顺序查找
#include <iostream>
#include <vector>

// 普通顺序查找
int SequentialSearch(std::vector<int>& nums, int key) {
    int numsSize = nums.size();
    for (int i = numsSize - 1; i >= 1; i--) {
        if (nums[i] == key) {
            return i;
        }
    }
    return 0;
}

// 设置监视哨的顺序查找
int SequentialSearchWithLookout(std::vector<int>& nums, int key) {
    nums[0] = key;
    int i   = nums.size() - 1;
    while (nums[i] != key) {
        i--;
    }
    return i;
}

int main(void) {
    std::vector<int> nums = {0, 1, 3, 2, 192, 11, 5};

    int pos = SequentialSearch(nums, 2);
    std::cout << pos << std::endl;

    pos = SequentialSearchWithLookout(nums, 1);
    std::cout << pos << std::endl;

    return 0;
}
