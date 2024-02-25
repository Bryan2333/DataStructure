#include <iostream>
#include <vector>

int LeftBoundBS(std::vector<int>& nums, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return LeftBoundBS(nums, target, left, mid - 1);
        } else if (nums[mid] < target) {
            return LeftBoundBS(nums, target, mid + 1, right);
        } else if (nums[mid] > target) {
            return LeftBoundBS(nums, target, left, mid - 1);
        }
    }
    return left;
}

int RightBoundBS(std::vector<int>& nums, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return RightBoundBS(nums, target, mid + 1, right);
        } else if (nums[mid] < target) {
            return RightBoundBS(nums, target, mid + 1, right);
        } else if (nums[mid] > target) {
            return RightBoundBS(nums, target, left, mid - 1);
        }
    }
    return right;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 2, 3};

    int leftPos = LeftBoundBS(nums, 2, 0, nums.size() - 1);
    std::cout << "leftPos=" << leftPos << std::endl;

    int rightPos = RightBoundBS(nums, 2, 0, nums.size() - 1);
    std::cout << "rightPos=" << rightPos << std::endl;

    return 0;
}
