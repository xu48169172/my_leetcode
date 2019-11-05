#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>

//邻接链表方法
#define MAX_NODE_NUM 100
enum Color {
    white,
    gray,
    black
};
struct Node {
    char vertex; //顶点信息
    int index;// 在node 表中的index
    int d; // 距离 // dfs is start time
    int f; // dfs end time
    int color; // white gray black
    struct Node* pi; // 广度优先搜索 记录
    struct Edge *first;// 邻接链表
};
struct Edge {
    int adj; // 邻接点
    struct Edge *next;// 邻接链表
};
struct Graph {
    struct Node node[MAX_NODE_NUM];
    unsigned int node_num;
    unsigned int edge_num;
    unsigned int matrix[MAX_NODE_NUM][MAX_NODE_NUM]; // 邻接矩阵
};

void create_graph(struct Graph *g)
{
    printf("please input node number and edge number:\n");
    scanf("%d%d", &g->node_num, &g->edge_num);
    printf("please input node information:\n");
    for (int i = 0; i < g->node_num; i++) {
        scanf(" %c", &g->node[i].vertex);
        g->node[i].first = NULL;
        g->node[i].index = i;
    }
    int i, j;
    printf("please input edge information, i, j:\n");

    for (int k = 0; k < g->edge_num; k++) {
        scanf("%d%d", &i, &j);
        struct Edge *e = (struct Edge *)malloc(sizeof(struct Edge));
        memset(e, 0 , sizeof(struct Edge));
        e->adj = j;
        e->next = g->node[i].first;
        g->node[i].first = e;
        g->matrix[i][j] = 1;
    }
}
void display_graph(struct Graph *g)
{
    for (int i = 0; i < g->node_num; i++) {
        printf("node %d: %c", i, g->node[i].vertex);
        for (struct Edge *e = g->node[i].first; e != NULL; e = e->next) {
            printf("->%c", g->node[e->adj].vertex);
        }
        printf("\n");
    }
}
struct queue {
    int head;
    int tail;
    int size;
    unsigned long data[MAX_NODE_NUM];
};
static struct queue Q;
struct stack {
    int top;
    unsigned long data[MAX_NODE_NUM];
};
static struct stack S;
void push(struct Node *node)
{
    if (S.top == MAX_NODE_NUM)
        return;
    S.data[S.top] = (uintptr_t)node;
    S.top++;
}
int is_stack_empty()
{
    return S.top == 0;
}
struct Node* pop(void)
{
    if (is_stack_empty())
        return NULL;
    S.top--;
    struct Node *e = (struct Node *)(S.data[S.top]);
    return e;
}
void enqueue(struct Node *node)
{
    if (Q.size == MAX_NODE_NUM)
        return;
    Q.data[Q.tail] = (uintptr_t)node;
    Q.tail++;
    if (Q.tail == MAX_NODE_NUM)
        Q.tail = 0;
    Q.size++;

}
int is_queue_empty(void)
{
    return (Q.size == 0);
}
struct Node* dequeue(void)
{
    if (is_queue_empty())
        return NULL;
    struct Node *e = (struct Node *)Q.data[Q.head];
    Q.head++;
    Q.size--;
    return e;
}
void print_path(struct Graph *g, struct Node *s, struct Node *v)
{
    if (s == v)
        printf("%c->", s->vertex);
    else if (v->pi == NULL)
        printf("No path from s to v");
    else {
        print_path(g, s, v->pi);
        printf("%c", v->vertex);
    }
}
void bfs(struct Graph *g)
{
    for(int i = 0; i < g->node_num; i++) {
        g->node[i].pi = NULL;
        g->node[i].color = white;
        g->node[i].d = 0;
    }
    g->node[0].color = gray;

    enqueue(&g->node[0]);
    while(!is_queue_empty()) {
        struct Node *u = dequeue();
#if 1
        // 邻接链表
        for(struct Edge *e = g->node[u->index].first;e != NULL; e = e->next) {
            struct Node *v = &g->node[e->adj];
            if (v->color == white) {
                v->color = gray;
                v->d = u->d + 1;
                v->pi = u;
                enqueue(v);
            }
        }
#else
        // 邻接矩阵
        for (int j = 0; j < g->node_num; j++) {
            if (g->matrix[u->index][j] == 1) {
                struct Node *v = &g->node[j];
                if (v->color == white) {
                    v->color = gray;
                    v->d = u->d + 1;
                    v->pi = u;
                    enqueue(v);
                }
            }
        }
#endif
        u->color = black;
    }
    print_path(g, &g->node[0], &g->node[1]);
    printf("\n");
    print_path(g, &g->node[0], &g->node[2]);
    printf("\n");
    print_path(g, &g->node[0], &g->node[3]);
    printf("\n");
    printf("Hello Breadth first search\n");
}
int time = 0;
void dfs_visit(struct Graph *g, struct Node *u)
{
    time = time + 1;
    u->d = time;
    u->color = gray;
    for(struct Edge *e = g->node[u->index].first;e != NULL; e = e->next) {
        struct Node *v = &g->node[e->adj];
        if (v->color == white) {
            v->pi = u;
            dfs_visit(g, v);
        }
    }
    u->color = black;
    time = time + 1;
    u->f = time;
    push(u);
}
void dfs(struct Graph *g)
{
    for(int i = 0; i < g->node_num; i++) {
        g->node[i].pi = NULL;
        g->node[i].color = white;
        g->node[i].d = 0;
    }
    for(int i = 0; i < g->node_num; i++) {
        struct Node *u = &g->node[i];
        if (u->color == white)
            dfs_visit(g, u);
    }
}
int main()
{
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    memset(g, 0, sizeof(struct Graph));
    create_graph(g);
    display_graph(g);
    //bfs(g);
    dfs(g);
    while(!is_stack_empty()){
        struct Node *e = pop();
        if (!is_stack_empty())
            printf("%c->",e->vertex);
        else
            printf("%c",e->vertex); 
    }
    printf("\n");
    return 0;
}