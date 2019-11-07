#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#if 0
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
0 7 8
7 8 7
2 8 2
8 6 6
2 5 4
3 5 14
1 7 11
#endif

/*
kruskal 算法
1 按照边进程降序排列
2 从最小的边开始取
3 查看两个点是否属于同一棵树
4 如果不是，将两个定点按照并查集的方法合并。
并查集：
另种方法：一种是采用数组的方案
另一种是采用父指针的方法。
*/
struct Node {
    int yank;
    struct Node *pi;
};
#define MAX_NODE_NUM 100
static struct Node node[MAX_NODE_NUM];
struct Edge {
    struct Node *u;
    struct Node *v;
    int weight;
};
static struct Edge edge[MAX_NODE_NUM];
void node_init(struct Node *u)
{
    u->pi = u;
    u->yank = 0;
}
int compare(const void *p0, const void *p1)
{
    struct Edge *u = (struct Edge*)p0;
    struct Edge *v = (struct Edge*)p1;
    return u->weight - v->weight;
}

struct Node* find_set(struct Node *node)
{
    if (node->pi != node)
        node->pi = find_set(node->pi);
    return node->pi;
}
void link(struct Node *x, struct Node *y)
{
    if (x->yank > y->yank)
        y->pi = x;
    else {
        x->pi = y;
        if (x->yank == y->yank)
            y->yank = y->yank + 1;
    }
}
void Union(struct Node *x, struct Node *y)
{
    link(find_set(x), find_set(y));
}
int main()
{
    int n, m;
    printf("please input node number and edge number:\n");
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
            node_init(&node[i]);
    }
    printf("please input edge information: u, v and weight\n");
    for (int i = 0; i < m; i++) {
        int k, j, weight;
        scanf("%d%d%d", &k, &j, &weight);
        struct Edge *e = &edge[i];
        e->u = &node[k];
        e->v = &node[j];
        e->weight = weight;
    }
    int sum = 0;
    qsort(edge, m, sizeof(struct Edge), compare);
    for (int i = 0; i < m; i++) {
        if (find_set(edge[i].u) != find_set(edge[i].v)) {
            sum = sum + edge[i].weight;
            Union(edge[i].u, edge[i].v);
        }
    }
    printf("sum= %d\n", sum);
    printf("Minimu spanning tree using kruskal algorithm\n");
}