#include <iostream>
#include <vector>

// 左侧边界二分查找
int LeftBoundBS(std::vector<int>& nums, int target) {
    int left  = 0;
    int right = nums.size() - 1;
    int mid   = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return left;
}

// 右侧边界二分查找
int RightBoundSearch(std::vector<int>& nums, int target) {
    int left  = 0;
    int right = nums.size() - 1;
    int mid   = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    return right;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 3, 3, 5};

    int leftPos = LeftBoundBS(nums, 3);
    std::cout << "LeftPost=" << leftPos << std::endl;

    int rightPos = RightBoundSearch(nums, 3);
    std::cout << "RightPost=" << rightPos << std::endl;

    return 0;
}
