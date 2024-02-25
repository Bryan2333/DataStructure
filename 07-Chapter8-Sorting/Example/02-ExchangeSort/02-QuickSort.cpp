// 快速排序
#include <iostream>
#include <vector>

void PrintArray(std::vector<int>&);

// 利用快慢指针进行分区
// [low, slow) < pivotkey  [slow, high] >= pivotkey
int Partition(std::vector<int>& nums, int low, int high) {
    // 选择数组最后一个元素作为枢纽
    int tmp  = nums[high];
    int slow = low;
    for (int fast = low; fast < high; fast++) {
        if (nums[fast] < tmp) {
            std::swap(nums[slow], nums[fast]);
            slow++;
        }
    }
    std::swap(nums[high], nums[slow]);
    return slow;
}

void QuickSort(std::vector<int>& nums, int low, int high) {
    if (low < high) {
        int pivotkey = Partition(nums, low, high);
        QuickSort(nums, low, pivotkey - 1);  // [low, pivotkey - 1]
        QuickSort(nums, pivotkey + 1, high); // [pivotkey + 1, high]
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
    QuickSort(nums, 0, nums.size() - 1);
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
