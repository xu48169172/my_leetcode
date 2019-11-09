#include <stdio.h>
#include <stdlib.h>
/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 找到下一个字典序
// 通过测试用例
int compare(void *p0, void *p1)
{
    return *(int *)p0 - *(int *)p1;
}
void nextPermutation(int* nums, int numsSize)
{
    int i;
    for (i = numsSize - 1; i >0; i--) {
        if (nums[i]> nums[i - 1]) {
            int j;
            int min_j=0;
            for (j = i; j < numsSize; j++) {
                long min = 0x7ffffffff;
                printf("%d\n", nums[j] - nums[i - 1]);
                if ((nums[j] - nums[i - 1] > 0) && (nums[j] - nums[i - 1] < min)) {
                    min = nums[j] - nums[i - 1];
                    min_j = j;
                }
            }
            int temp;
            temp = nums[min_j];
            nums[min_j] = nums[i - 1];
            nums[i - 1] = temp;
            qsort(&nums[i], numsSize - i, sizeof(int), compare);
            return;
        }
    }
    if (i == 0) {
        qsort(nums, numsSize, sizeof(int), compare);
    }
}
int main()
{
    //int nums[] = {1,2,3,4};
    //int nums[] = {1,2,4,4};
    //int nums[] = {1,4,4,4,6,3};
    //int nums[] = {5,4,3,2,1};
    int nums[] = {1,3,2};
    nextPermutation(nums, sizeof(nums)/sizeof(int));
    for (int i = 0 ; i < sizeof(nums)/sizeof(int); i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\nHello World\n");
}