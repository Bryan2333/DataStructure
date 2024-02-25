// 二分插入排序
#include <iostream>
#include <vector>

// 通过二分查找确定元素插入位置
int BinarySearchPos(std::vector<int>& nums, int val, int end) {
    int right = end;
    int left  = 0;
    int mid   = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (val < nums[mid]) {
            right = mid - 1;
        } else if (val > nums[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return left;
}

void BinaryInsertionSort(std::vector<int>& nums) {
    int numsSize = nums.size();
    for (int i = 1; i < numsSize; i++) {
        int tmp = nums[i];

        int pos = BinarySearchPos(nums, tmp, i - 1);

        for (int j = i - 1; j >= pos; j--) {
            nums[j + 1] = nums[j];
        }

        nums[pos] = tmp;
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
    BinaryInsertionSort(nums);
    std::cout << "排序后: ";
    PrintArray(nums);

    return 0;
}
