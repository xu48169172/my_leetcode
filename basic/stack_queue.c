#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define STACK_BLOCK_SIZE 10
#define QUEUE_BLOCK_SIZE 10
struct queue {
    int tail;
    int head;
    int *data;
    int block_size;
    int size;
};
void enqueue(struct queue *q, int val)
{
    if (q->data == NULL) {
        q->size = q->block_size = QUEUE_BLOCK_SIZE;
        q->data = calloc(q->size, sizeof(int));   
    }
    if (q->tail == q->size) {
        int old_size = q->size;
        q->size = q->size + q->block_size;
        int *second = calloc(q->size, sizeof(int));
        if (second == NULL) {
            printf("realloc error\n");
        } else {
            memcpy(second, q->data, old_size * sizeof(int));
            free(q->data);
            q->data = second;
        }
    }
    q->data[q->tail] = val;
    q->tail++;
}
int is_queue_empty(struct queue *q)
{
    return q->size == 0;
}
int dequeue(struct queue *q)
{
    int temp = q->data[q->head];
    q->head++;
    q->size--;
    return temp;
}
struct stack {
    int top;
    int block_size;
    int *data;
    int size;
};
void push(struct stack *p, int val)
{
    if (p->data == NULL) {
        p->size = p->block_size = STACK_BLOCK_SIZE;
        p->data = calloc(p->size, sizeof(int));
    }
    if (p->top == p->size) {
        int old_size = p->size;
        p->size = p->size + p->block_size;
        int *second = calloc(p->size, sizeof(int));
        if (second == NULL) {
            printf("realloc stack error\n");
            return;
        } else {
            memcpy(second, p->data, old_size * sizeof(int));
            free(p->data);
            p->data = second;
        }
    }
    p->data[p->top] = val;
    p->top++;
}
int is_stack_empty(struct stack *p)
{
    return p->top == 0;
}
int pop(struct stack *p)
{
    p->top--;
    return p->data[p->top];
}

int main()
{
    struct stack *p = calloc(1, sizeof(struct stack));
    for (int i = 0; i < 20; i++) {
        push(p, i);
    }
    while(!is_stack_empty(p)) {
        printf("%d ",pop(p));
    }
    printf("\n");

    struct queue *q = calloc(1, sizeof(struct queue));
    for (int i = 0; i < 20; i++) {
        enqueue(q, i);
    }
    while(!is_queue_empty(q)) {
        printf("%d ",dequeue(q));
    }
    printf("\n");
}