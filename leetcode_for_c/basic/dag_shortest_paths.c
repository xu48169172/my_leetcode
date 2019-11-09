#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum Color {
    white,
    gray,
    black
};
struct Edge {
    struct Node *v;
    struct Edge *next;
    int weight;
};
struct Node {
    char vertex;
    struct Edge *first;
    int index;
    int s; //start time
    int f; //end time
    struct Node *p;
    int d;
    int color;
};
#define MAX_NODE_NUM 100
#define MAX_EDGE_NUM 100
struct Graph {
    int node_num;
    int edge_num;
    struct Node node[MAX_NODE_NUM];
    struct Edge edge[MAX_EDGE_NUM];
};
struct stack {
    int top;
    unsigned long data[MAX_NODE_NUM];
};
static struct stack s;
void push(struct Node *u)
{
    if (s.top == MAX_NODE_NUM)
        return;
    s.data[s.top] = (uintptr_t)u;
    s.top++;
}
bool is_stack_empty(void)
{
    return s.top == 0;
}
struct Node* pop(void)
{
    if (is_stack_empty())
        return NULL;
    s.top--;
    return (struct Node*)s.data[s.top];
}
static int time;
void dfs_visit(struct Node *u)
{
    struct Edge *e;
    struct Node *v;
    time++;
    u->s = time;
    u->color = gray;
    for (e = u->first; e != NULL; e = e->next) {
            v = e->v;
            if (v->color == white) {
                dfs_visit(v);
            }
    }
    u->color = black;
    time++;
    u->f = time;
    push(u);
}
void dfs(struct Graph *g)
{
    struct Node *u;
    for (int i = 0; i < g->node_num; i++) {
        u = &g->node[i];
        if (u->color == white)
            dfs_visit(u);
    }
}
void relax(struct Node *u, struct Node *v, struct Edge *e)
{
    if (v->d > u->d + e->weight) {
        v->d = u->d + e->weight;
        v->p = u;
    }
}
void print_path(struct Node *v)
{
    if (v->p == NULL) {
        printf("%c", v->vertex);
        return;
    } else {
        print_path(v->p);
        printf("->%c", v->vertex);
    }
}
int main()
{
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    struct Edge *e;
    struct Node *u;
    struct Node *v;
    memset(g, 0, sizeof(struct Graph));
    printf("please input node num and edge num:\n");
    scanf("%d%d", &g->node_num, &g->edge_num);
    for (int i = 0; i < g->node_num; i++) {
        scanf(" %c", &g->node[i].vertex);
        g->node[i].index = i;
    }
    int k, j, weight;
    for (int i = 0; i < g->edge_num; i++) {
        e = &g->edge[i];
        scanf("%d%d%d", &k, &j, &weight);
        e->v = &g->node[j];
        e->weight = weight;
        u = &g->node[k];
        e->next = u->first;
        u->first = e;
    }
    dfs(g);
    for (int i = 0; i < g->node_num; i++) {
        u = &g->node[i];
        u->p = NULL;
        u->d = 100000;
    }
    struct Node *s = &g->node[0];
    s->d = 0;
    while(!is_stack_empty()) {
        struct Node *u = pop();
        for (e = u->first; e != NULL; e = e->next) {
            v = e->v;
            relax(u, v, e);
        }
        print_path(u);
        printf("\n");
    }

    printf("\nHello Dag Shortest Paths\n");
}
#if 0
s t x y z
5 8
0 1 2
0 2 6
1 2 7
1 3 4
1 4 2
2 3 -1
2 4 1
3 4 -2
#endif