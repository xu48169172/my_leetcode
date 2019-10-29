/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
解题思路：
按照字典序排列
*/
int compare(const void *p0, const void *p1)
{
    return *(int *)p0 - *(int *)p1;
}
int **result;
void nextpermute(int* nums, int numsSize, int *index)
{
    for (int i = numsSize - 1; i >0; i--) {
        if (nums[i] > nums[i - 1] > 0) {
            long min = 0x7ffffffff;
            int min_j = 0;
            for (int j = i; j < numsSize; j++) {
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
            *(result + (*index)) = malloc(sizeof(int) * numsSize);
            memcpy(*(result + (*index)), nums, sizeof(int) * numsSize);
            (*index)++;
            nextpermute(nums, numsSize, index);
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int rows = 1;
    for (int i = 0; i < numsSize; i++) {
        rows = rows * ( i + 1);
    }
    result = malloc(sizeof(int *) * rows);
    int index = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    *(result + index) = malloc(sizeof(int) * numsSize);
    memcpy(*(result + index), nums, sizeof(int) * numsSize);
    index++;
    nextpermute(nums, numsSize, &index);
    *returnColumnSizes = malloc(sizeof(int) * index);
    for (int i = 0; i < index; i++) {
        *(*returnColumnSizes + i) = numsSize;
    }
    *returnSize = index;   
    return result;
}

int main()
{
    int nums[3]={1, 2, 3};
    int resturnSize;
    int *returnColumnSizes;
    int **result = permuteUnique(nums, sizeof(nums)/sizeof(int), &resturnSize, &returnColumnSizes);
    for (int i = 0; i < resturnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
           printf("%d ", result[i][j]); 
        }
        printf("\n");
    }
    printf("\nHello world\n");
}