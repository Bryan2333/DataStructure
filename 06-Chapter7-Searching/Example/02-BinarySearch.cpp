// 二分查找
#include <iostream>
#include <vector>

// 二分查找迭代实现
int BinarySearchLoop(std::vector<int>& nums, int target) {
    int left  = 1;               // 第一个元素的位置
    int right = nums.size() - 1; // 最后一个元素的位置
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2; // 防止 left+right 过大溢出
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    return -1;
}

// 二分查找递归实现
int BinarySearchRecursive(std::vector<int>& nums, int target, int left,
                          int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return BinarySearchRecursive(nums, target, mid + 1, right);
        } else if (nums[mid] > target) {
            return BinarySearchRecursive(nums, target, left, mid - 1);
        }
    }
    return -1;
}

int main(void) {
    std::vector<int> nums = {1, 2, 3, 3, 3, 5};

    int posLoop = BinarySearchLoop(nums, 3);
    std::cout << "posLoop=" << posLoop << std::endl;

    int posRecursive = BinarySearchRecursive(nums, 23, 1, nums.size() - 1);
    std::cout << "posRecursive=" << posRecursive << std::endl;

    return 0;
}
