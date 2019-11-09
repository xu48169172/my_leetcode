/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 深度优先搜索的方法实现没有重复数字的全排列
enum color {
    white,
    gray
};
struct Node {
    int vertex;
    int color;
    struct Edge *first;
};
struct Edge {
    struct Node *u;
    struct Node *v;
    struct Edge *next;
};
struct Graph {
    int **matrix;
};
int depth;
int **result;
int *p;
int row = 0;
int rows = 1;
void dfs_visit(struct Node *u, int index)
{
    u->color = gray;
    printf("row=%d\n", row);
    result[row][index] = u->vertex;
    if (index == depth - 1) {
        row++;
        if (row == rows)
            return;
        for (int i = 0; i < depth; i++)
            result[row][i] = result[row - 1][i];
        return;
    }
    for (struct Edge *e = u->first; e != NULL; e = e->next) {
        struct Node *v = e->v;
        if (v->color == white) {
            dfs_visit(v, index + 1);
            v->color = white;
        }
    }
}
void Free(struct Edge *e)
{
    if (e != NULL) {
        Free(e->next);
        free(e);
        e = NULL;
    } else {
        return;
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    row = 0;
    rows = 1;
    for (int i = 0; i < numsSize; i++) {
        rows = rows * (i + 1);
    }
    depth = numsSize;
    result = malloc(sizeof(int *) * 0xffff);
    for (int i = 0 ; i < rows; i++) {
        *(result + i) = malloc(sizeof(int) * numsSize);
    }
    struct Node *nodes = malloc(sizeof(struct Node) * numsSize);
    memset(nodes, 0 ,sizeof(struct Node) * numsSize);
    for (int i = 0;i < numsSize;i++) {
        nodes[i].vertex = nums[i];
        for (int j = i +1;j < numsSize;j++) {
            struct Edge *e = malloc(sizeof(struct Edge));
            e->u = &nodes[i];
            e->v = &nodes[j];
            e->next = nodes[i].first;
            nodes[i].first = e;

            e = malloc(sizeof(struct Edge));
            e->u = &nodes[j];
            e->v = &nodes[i];
            e->next = nodes[j].first;
            nodes[j].first = e;
        }
    }

    for (int i = 0; i < numsSize;i++) {
        struct Node *u = &nodes[i];
        dfs_visit(u, 0);
        u->color = white;
    }
    for (int i = 0; i < numsSize;i++) {
        struct Node *u = &nodes[i];
        Free(u->first);
    }
    free(nodes);
    nodes = NULL;
    *returnSize = rows;
    p = malloc(sizeof(int) * 0xffff);
    for (int i = 0; i < rows; i++) {
        p[i] = numsSize;
    }
    *returnColumnSizes = p；
    return result;
}

int main()
{
    int n = 1;
    int *p1 = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        p1[i] = i + 1;
    }
    int returnsize;
    int **result;
    int *columSize;
    result = permute(p1, n, &returnsize, &columSize);
    for (int i = 0; i < returnsize; i++) {
        for (int j = 0; j < columSize[i]; j++) {
                printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    free(p1);
}