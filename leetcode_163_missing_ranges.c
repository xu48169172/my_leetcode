#include <stdio.h>
#include <malloc.h>
#include <string.h>
/* leetcode 163 */
/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/
/*
给定一个排序的整数数组 nums ，其中元素的范围在 闭区间 [lower, upper] 当中，返回不包含在数组中的缺失区间。

示例：

输入: nums = [0, 1, 3, 50, 75], lower = 0 和 upper = 99,
输出: ["2", "4->49", "51->74", "76->99"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/missing-ranges
*/
/*
解题思路： 首先数组的元素是在 【lower，upper】 区间内， 因此lower 一定是最left的值，遍历数组
一定要考虑 lower 和 upper 可能是整数的边界值。
2147483647
*/
char ** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize)
{
    char **m = malloc((numsSize + 1) * sizeof(char *));
    if (m == NULL) {
        *returnSize = 0;
        return NULL;
    }
    long left = (long)lower - 1;
    long val = 0;
    int buffersize = 30;
    int n = 0;
    void *p = malloc(buffersize);
    if (p == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(p, 0, buffersize);
    int mcnt = 0;

    int i = 0;
    for (i = 0; i < numsSize; i ++) {
        //printf("%ld,%d\n",left,nums[i]);
        val = nums[i] - left;
        if (val == 2) {
            p = malloc(buffersize);
            memset(p, 0, buffersize);
            m[mcnt] = p;
            mcnt ++;
            n = sprintf(p,"%ld",left + 1);
        } else if( val > 2) {
            p = malloc(buffersize);
            memset(p, 0, buffersize);
            m[mcnt] = p;
            mcnt ++;
            n = sprintf(p,"%ld->%d", left + 1, nums[i]-1);
        }
        left = nums[i];
    }
    val = upper - left;
    if (val == 1) {
        p = malloc(buffersize);
        memset(p, 0, buffersize);
        m[mcnt] = p;
        mcnt++;
        n = sprintf(p,"%d",upper);
    } else if ( val > 1) {
        p = malloc(buffersize);
        memset(p, 0, buffersize);
        m[mcnt] = p;
        mcnt++;
        n = sprintf(p,"%ld->%d", left + 1, upper);
    }
    *returnSize = mcnt;
    return m;
}
int main()
{
    printf("Hello World\n");
    int a[] = {0,1,3,20,40};
    int returnSize = 0;
    char ** res = findMissingRanges(a, 5, 0, 99, &returnSize);
    for (int i =0; i < returnSize; i ++)
        printf("%s\n",res[i]);
    return 0;
}