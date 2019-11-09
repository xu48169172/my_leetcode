#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define N 200
struct queue {
    int head;
    int tail;
    int size;
    int data[N];
};
struct stack {
    int top;
    int data[N];
};
int push(struct stack* p, int tmp)
{
    p->data[p->top] = tmp;
    p->top++;
}
int is_stack_empty(struct stack* p)
{
    return p->top == 0;
}
int pop(struct stack* p)
{
    if (is_stack_empty(p))
        return -1;
    p->top--;
    return p->data[p->top];
}
int check_stack(struct stack *p)
{
    int top = p->data[p->top -1];
    for (int i = p->top -1 -1; i >=0; i--) {
        if (top == p->data[i]) {
            return (p->top - i);
        }
    }
    return 0;
}
int enqueue(struct queue *q, int tmp)
{
    q->data[q->tail] = tmp;
    q->tail = (q->tail + 1) % N;
    q->size ++;
}
int is_queue_empty(struct queue *q)
{
    return q->size == 0;
}
int dequeue(struct queue* q)
{
    if (is_queue_empty(q))
        return -1;   
    int x = q->data[q->head];
    q->head++;
    q->size--;
    q->head = q->head % N;
    return x;
}
int main()
{
    int n;
    scanf("%d", &n);
    struct queue *mm = malloc(sizeof(struct queue));
    memset(mm, 0, sizeof(struct queue));
    struct queue *xx = malloc(sizeof(struct queue));
    memset(xx, 0, sizeof(struct queue));
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        enqueue(mm, m);
    }
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        enqueue(xx, m);
    }
    struct stack* s = malloc(sizeof(struct stack));
    memset(s, 0, sizeof(struct stack));
#if 0
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        push(s, m);
    }
    while(!is_stack_empty(s))
        printf("%d",pop(s));
    printf("\n");

    while (!is_queue_empty(mm))
        printf("%d", dequeue(mm));
    printf("\n");
    while (!is_queue_empty(xx))
        printf("%d", dequeue(xx));
    printf("\n");
#endif
    int number = 0;
    while(!is_queue_empty(mm) && !is_queue_empty(xx)) {
        number++;
        int chart = dequeue(mm);
        push(s, chart);
        int n = check_stack(s);
        if (n) {
            for (int i = 0; i<n; i++) {
                enqueue(mm, pop(s));
            }
        }
        chart = dequeue(xx);
        push(s, chart);
        n = check_stack(s);
        if (n) {
            for (int i = 0; i<n; i++) {
                enqueue(xx, pop(s));
            }
        }
    }
    printf("%d\n",number);
    if (!is_queue_empty(mm))
        printf("mm\n");
    while (!is_queue_empty(mm)) {
        if (mm->size == 1)
            printf("%d",dequeue(mm));
        else
            printf("%d#",dequeue(mm));
    }
    if (!is_queue_empty(xx))
        printf("xx\n");
    while (!is_queue_empty(xx)) {
        if (xx->size == 1)
            printf("%d",dequeue(xx));
        else
            printf("%d#",dequeue(xx));
    }
    printf("\nHello World\n");
    return 0;
}