#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

struct Node {
    char vertex;
    int d;// distance
    struct Node *p;
};
struct Edge {
    struct Node *u;// from
    struct Node *v;// to
    int weight;
};
#define MAX_NODE_NUM 100
#define MAX_EDGE_NUM 100
struct Graph {
    struct Node node[MAX_NODE_NUM];
    struct Edge edge[MAX_EDGE_NUM];
    int node_num;
    int edge_num;
};
void initialize_single_source(struct Graph *g, struct Node *s)
{
    for (int i = 0; i < g->node_num; i++) {
        g->node[i].d = 100000;
        g->node[i].p = NULL;
    }
    s->d = 0;
}
void relax(struct Node *u, struct Node *v, struct Edge *e)
{
    if ( v->d > (u->d + e->weight)) {
        v->d = u->d + e->weight;
        v->p = u;
    }
}
bool bellman_ford(struct Graph *g)
{
    struct Node *s = &g->node[0];
    initialize_single_source(g, s);
    struct Node *u;
    struct Node *v;
    struct Edge *e;
    for (int i = 0; i < g->node_num - 1; i++) {
        for (int j = 0; j < g->edge_num; j++) {
            u = g->edge[j].u;
            v = g->edge[j].v;
            e = &g->edge[j];
            relax(u, v, e);
        }
    }
    for (int i = 0; i < g->node_num - 1; i++) {
        u = g->edge[i].u;
        v = g->edge[i].v;
        e = &g->edge[i];
        if (v->d > u->d + e->weight)
            return false;
    }
    return true;
}
void print_path(struct Node *v)
{
    if (v->p == NULL) {
        printf("%c", v->vertex);
    }
    else {
        print_path(v->p);
        printf("->%c", v->vertex);
    }
}
int main()
{
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    memset(g, 0, sizeof(struct Graph));
    printf("please input node num and edge num:\n");
    scanf("%d%d", &g->node_num, &g->edge_num);
    for (int i = 0; i < g->node_num; i++) {
        scanf(" %c", &g->node[i].vertex);
    }
    printf("please input u v and weight:\n");
    for (int i = 0; i < g->edge_num; i++) {
        int u, v, weight;
        scanf("%d%d%d", &u, &v, &weight);
        g->edge[i].u = &g->node[u];
        g->edge[i].v = &g->node[v];
        g->edge[i].weight = weight;
    }
    if (bellman_ford(g)) {
        for (int i = 1; i < g->node_num; i++) {
            struct Node *u = &g->node[i];
            printf("%c:%d\n", u->vertex, u->d);
            print_path(u);
            printf("\n");
        }
    }
    printf("Hello Bellman Ford For single source shortest path\n");
    return 0;
}
#if 0
page 379
5 10
a t x y z
0 1 6
0 3 7
1 2 5
1 3 8
1 4 -4
2 1 -2
3 2 -3
3 4 9
4 2 7
4 0 2
#endif