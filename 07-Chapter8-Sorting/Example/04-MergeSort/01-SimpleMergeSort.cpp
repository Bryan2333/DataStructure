// 归并排序
#include <iostream>
#include <vector>

void PrintArray(std::vector<int>&);
void swap(int*, int*);

void Merge(std::vector<int>& nums, int start, int mid, int end) {
    // 将数组分为两部分
    // leftPart  [begin + start, begin + mid]
    // rightPart [begin + mid + 1, begin + end]
    int leftPartSize  = mid - start + 1;
    int rightPartSize = end - mid;

    std::vector<int> leftPart(nums.begin() + start, nums.begin() + mid + 1);
    std::vector<int> rightPart(nums.begin() + mid + 1, nums.begin() + end + 1);
    // int *leftPart  = malloc(sizeof(int) * leftPartSize);
    // int *rightPart = malloc(sizeof(int) * rightPartSize);

    // memmove(leftPart, nums + start, sizeof(int) * leftPartSize);
    // memmove(rightPart, nums + mid + 1, sizeof(int) * rightPartSize);

    int i = 0;
    int j = 0;
    int k = start; // 每部分相对的起始位置
    while (i < leftPartSize && j < rightPartSize) {
        if (leftPart[i] < rightPart[j]) {
            nums[k] = leftPart[i];
            i++;
        } else {
            nums[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftPartSize) {
        nums[k] = leftPart[i];
        k++;
        i++;
    }

    while (j < rightPartSize) {
        nums[k] = rightPart[j];
        k++;
        j++;
    }

    // free(leftPart);
    // free(rightPart);
}

void MergeSort(std::vector<int>& nums, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        MergeSort(nums, start, mid);   // 左半部分 [start, mid]
        MergeSort(nums, mid + 1, end); // 右半部分 [mid + 1, end]
        Merge(nums, start, mid, end);
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
    MergeSort(nums, 0, nums.size() - 1);
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
