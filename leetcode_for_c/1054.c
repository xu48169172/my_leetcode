#if 0
在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。

请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，此题保证存在答案。

 

示例 1：

输入：[1,1,1,2,2,2]
输出：[2,1,2,1,2,1]
示例 2：

输入：[1,1,1,1,2,2,3,3]
输出：[1,3,1,3,2,1,2,1]
 

提示：

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distant-barcodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#endif
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#if 0
使用深度优先搜索导致执行超时
enum Color {
    white,
    gray,
    black
};
struct Node {
    int color;
    int val;
    int index;
};
char **matrix;
int *out;
struct stack {
    int top;
    int *data;
};
struct stack *p;
void push(int temp)
{
    p->data[p->top] = temp;
    p->top++;
}
void pop()
{
    if (p->top == 0)
        return;
    p->top--;
    p->data[p->top] = 0;
}

int dfs(struct Node *nodes, struct Node *u, int len) {
    u->color = gray;
    push(u->val);
    if (p->top == len)
        return 1;
    for (int i = 0; i < len; i++) {
        if (matrix[u->index][i]) {
            struct Node *v = &nodes[i];
            if ((v->color == white) && (v->val != u->val)) {
                printf("%d\n", i);
                int ret = dfs(nodes, &nodes[i], len);
                if (ret)
                    return ret;
                v->color = white;
                pop();
            }
        }
    }
    return 0;
}
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize)
{
    matrix= malloc(barcodesSize * sizeof(char *));
    for (int i = 0; i < barcodesSize; i++) {
        *(matrix + i) = malloc(barcodesSize);
        memset(*(matrix + i), 1, barcodesSize);
    }
    for (int i = 0; i < barcodesSize; i++) {
        matrix[i][i] = 0;
    }
    struct Node *nodes = malloc(sizeof(struct Node) * barcodesSize);
    for (int i = 0; i < barcodesSize; i++) {
        nodes[i].color = white;
        nodes[i].val = barcodes[i];
        nodes[i].index = i;
    }
    p = malloc(sizeof(struct stack));
    memset(p, 0, sizeof(struct stack));
    p->data = malloc(sizeof(int) * barcodesSize);
    memset(p->data, 0, sizeof(int) * barcodesSize);
    for (int i = 0; i < barcodesSize; i++) {
        printf("%d\n", i);
        int ret = dfs(nodes, &nodes[i], barcodesSize);
        if (ret)
            break;
        pop();
        nodes[i].color = white;
    }
    *returnSize = p->top;

    for (int i = 0; i < barcodesSize; i++) {
        free(*(matrix + i));
    }
    free(matrix);
    return p->data;
}
#endif
#if 0
struct Node {
    int count;
    int val;
    int can_visit;
};
int compare(void *p0, void *p1)
{
    struct Node *s0 = (struct Node *)p0;
    struct Node *s1 = (struct Node *)p1;
    if (s0->count > s1->count)
        return -1;
    else
        return 1;
}
struct Node *get_max(struct Node *nodes, struct Node *n, int *last_i, int num)
{
    int max_count = 0;
    int max_i = 0;
    for (int i = 0; i < num; i++) {
        if (nodes[i].can_visit && nodes[i].count > max_count) {
            max_count = nodes[i].count;
            max_i = i;
        }
    }
    *last_i = max_i;
    if (n)
        n->can_visit = 1;
    return &nodes[max_i];
}
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize)
{
    struct Node nodes[10001];
    memset(&nodes, 0, sizeof(struct Node) * 10001);
    for (int i = 0; i < barcodesSize; i++) {
        nodes[barcodes[i]].val = barcodes[i];
        nodes[barcodes[i]].count++;
    }
    qsort(&nodes, 10001, sizeof(struct Node), compare);
    int num = 0;
    for (int i = 0; i < barcodesSize;i++) {
        if (nodes[i].count == 0)
            break;
        else {
            //nodes[i].can_visit = 1;
            num++;
        }
    }
    int *out = malloc(sizeof(int) * barcodesSize);
    struct Node *max = NULL;
    int last_i = 0;
    nodes[0].can_visit = 1;
    for (int i = 0 ; i < barcodesSize; i++) {
        max = get_max(nodes, max, &last_i, num);
#if 0
        printf("last_i:%d\n", last_i);
        {
            for (int i = 0; i < num; i++) {
                printf("%d->%d;", nodes[i].val, nodes[i].count);
            }
            printf("\n");
        }
#endif
        out[i] = max->val;
        max->count--;
        max->can_visit = 0;
        nodes[last_i + 1].can_visit = 1;
    }
    *returnSize = barcodesSize;
    return out;
}

int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize)
{
    struct Node nodes[10001];
    memset(&nodes, 0, sizeof(struct Node) * 10001);
    for (int i = 0; i < barcodesSize; i++) {
        nodes[barcodes[i]].val = barcodes[i];
        nodes[barcodes[i]].count++;
    }
    qsort(&nodes, 10001, sizeof(struct Node), compare);
    int num = 0;
    for (int i = 0; i < barcodesSize;i++) {
        if (nodes[i].count == 0)
            break;
        else {
            //nodes[i].can_visit = 1;
            num++;
        }
    }
    int *out = malloc(sizeof(int) * barcodesSize);
    struct Node *max = NULL;
    int last_i = 0;
    nodes[0].can_visit = 1;
    for (int i = 0 ; i < barcodesSize; i++) {
        max = get_max(nodes, max, &last_i, num);
#if 0
        printf("last_i:%d\n", last_i);
        {
            for (int i = 0; i < num; i++) {
                printf("%d->%d;", nodes[i].val, nodes[i].count);
            }
            printf("\n");
        }
#endif
        out[i] = max->val;
        max->count--;
        max->can_visit = 0;
        nodes[last_i + 1].can_visit = 1;
    }
    *returnSize = barcodesSize;
    return out;
}
#endif
/*
[
51,83,51,40,51,40,51,40,83,40,83,83,51,40,40,51,51,51,40,40,40,83,51,51,40,51,51,40,40,51,51,40,51,51,51,40,83,40,40,83,51,51,51,40,40,40,51,51,83,83,40,51,51,40,40,40,51,40,83,40,83,40,83,40,51,51,40,51,51,51,51,40,51,83,51,83,51,51,40,51,40,51,40,51,40,40,51,51,51,40,51,83,51,51,51,40,51,51,40,40]
51,83,51,40,51,40,51,40,83,40,83,83,51,40,40,51,51,51,40,40,40,83,51,51,40,51,51,40,40,51,51,40,51,51,51,40,83,40,40,83,51,51,51,40,40,40,51,51,83,83,40,51,51,40,40,40,51,40,83,40,83,40,83,40,51,51,40,51
*/
struct Node {
    int count;
    int val;
};
int compare(void *p0, void *p1)
{
    struct Node *s0 = (struct Node *)p0;
    struct Node *s1 = (struct Node *)p1;
    if (s0->count > s1->count)
        return -1;
    else
        return 1;
}
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize)
{
    struct Node nodes[10001];
    memset(&nodes, 0, sizeof(struct Node) * 10001);
    for (int i = 0; i < barcodesSize; i++) {
        nodes[barcodes[i]].val = barcodes[i];
        nodes[barcodes[i]].count++;
    }
    qsort(&nodes, 10001, sizeof(struct Node), compare);
    int num = 0;
    for (int i = 0; i < barcodesSize;i++) {
        if (nodes[i].count == 0)
            break;
        else {
            num++;
        }
    }
    int *out = malloc(sizeof(int) * barcodesSize);
    struct Node *max = NULL;
    int last_i = 0;
    int k = 0;
    for (int i = 0 ; i < num; i++) {
        for (int j = 0; j < nodes[i].count; j++) {
            out[k] = nodes[i].val;
            k = k + 2;
            if (k >= barcodesSize)
                k = 1;
        }
    }
    *returnSize = barcodesSize;
    return out;
}
int main()
{
    //int a[] = {51,83,51,40,51,40,51,40,83,40,83,83,51,40,40,51,51,51,40,40,40,83,51,51,40,51,51,40,40,51,51,40,51,51,51,40,83,40,40,83,51,51,51,40,40,40,51,51,83,83,40,51,51,40,40,40,51,40,83,40,83,40,83,40,51,51,40,51};
    int a[] = {51,83,51,40,51,40,51,40,83,40,83,83,51,40,40,51,51,51,40,40,40,83,51,51,40,51,51,40,40,51,51,40,51,51,51,40,83,40,40,83,51,51,51,40,40,40,51,51,83,83,40,51,51,40,40,40,51,40,83,40,83,40,83,40,51,51,40,51,51,51,51,40,51,83,51,83,51,51,40,51,40,51,40,51,40,40,51,51,51,40,51,83,51,51,51,40,51,51,40,40};
    //int a[] = {1,1,1,1,2,2,3,3};

    int returnSize = 0;;
    
    int *output = rearrangeBarcodes(a, sizeof(a)/sizeof(a[0]), &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
}