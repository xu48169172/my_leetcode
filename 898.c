#include <stdio.h>
#include <stdlib.h>
// 超时 
// 解题思路： 两层循环，计算 或操作，通过一个数组统计 加入的数字是否重复，qosrt 排序，加上二分查找。
int binary_search(int *out, int key, int num)
{
    int left = 0;
    int right = num - 1;
    int flag = 0;
    if (num == 0)
        return flag;
    if (key < out[left] || key > out[right])
        return flag;
    while (left <= right) {
        int mid = (right + left)/2;
        if (key < out[mid]) {
            right = mid - 1;
        } else if (key > out[mid]) {
            left = mid + 1;
        } else {
            flag = 1;
            break;
        }
    }
    return flag;
}
int compare(const void *p0, const void *p1)
{
    int a0 = *(int *)p0;
    int a1 = *(int *)p1;
    return a0- a1;
}
int insert(int *out, int key, int num)
{
    if (binary_search(out, key, num))
        return num;
    out[num] = key;
    num++;
    qsort(out, num, sizeof(int), compare);
    return num;
}
int subarrayBitwiseORs(int* A, int ASize)
{
    int sum = 1;
    sum = (ASize * (ASize + 1)) /2;
    int *out = malloc(sizeof(int) * sum);
    int num = 0;
    int **p = malloc(sizeof(int *) * ASize);
    for (int i = 0; i < ASize; i++) {
        *(p + i) = malloc(sizeof(int) * (ASize - i));
        p[i][i - i] = A[i];
        num = insert(out, p[i][i - i], num);
        //printf("[%d-%d]=%d, ", i, i, p[i][i - i]);
        for (int j = i + 1; j < ASize; j++) {
            p[i][j - i] = p[i][j - i - 1] | A[j];
            //printf("[%d-%d]=%d, ", i, j, p[i][j - i]);
            if (p[i][j - i] > p[i][j - i - 1])
                num = insert(out, p[i][j - i], num);
        }
        //printf("\n");
    }
#if 0
    for (int i = 0; i < num; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
#endif
    free(out);
    for (int i = 0; i < ASize; i++) {
        free(*(p + i));
    }
    free(p);
    return num;
}
int main()
{
    int A[] = {3, 11};
    printf("%d\n", subarrayBitwiseORs(A, sizeof(A)/sizeof(int)));
}

#if 0
我们有一个非负整数数组 A。

对于每个（连续的）子数组 B = [A[i], A[i+1], ..., A[j]] （ i <= j），我们对 B 中的每个元素进行按位或操作，获得结果 A[i] | A[i+1] | ... | A[j]。

返回可能结果的数量。 （多次出现的结果在最终答案中仅计算一次。）

 

示例 1：

输入：[0]
输出：1
解释：
只有一个可能的结果 0 。
示例 2：

输入：[1,1,2]
输出：3
解释：
可能的子数组为 [1]，[1]，[2]，[1, 1]，[1, 2]，[1, 1, 2]。
产生的结果为 1，1，2，1，3，3 。
有三个唯一值，所以答案是 3 。
示例 3：

输入：[1,2,4]
输出：6
解释：
可能的结果是 1，2，3，4，6，以及 7 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bitwise-ors-of-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#endif