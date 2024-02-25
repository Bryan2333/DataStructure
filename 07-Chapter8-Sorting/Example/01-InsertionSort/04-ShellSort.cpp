// 希尔排序
#include <iostream>
#include <vector>

void ShellSort(std::vector<int>& nums) {
    int gap;
    int i;
    int j;

    for (gap = numsSize / 2; gap > 0; gap = gap / 2) {
        for (i = gap; i < numsSize; i++) {
            nums[0] = nums[i]; // 用r[0]保存当前元素的值
            for (j = i; j >= gap && nums[j - gap] > nums[0]; j = j - gap) {
                nums[j] = nums[j - gap];
            }
            nums[j] = nums[0];
        }
    }
}

void PrintArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(void) {
    int nums[]   = {0, 1, 0, 3, 2, 5, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("排序前: ");
    PrintArray(nums, numsSize);
    ShellSort(nums, numsSize);
    printf("排序后: ");
    PrintArray(nums, numsSize);

    return 0;
}
