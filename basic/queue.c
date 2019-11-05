#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Data {
    int data;
};
struct queue {
    int tail;
    int head;
    struct Data *data;
    int size;
    int capacity;
};
void queue_debug(struct queue *q)
{
    printf("==========\n");
    for (int i = 0; i < q->capacity; i++) {
        printf("%d ", q->data[i].data);
    }
    printf("\nhead:%d, tail:%d, size:%d, capacity:%d\n", q->head, q->tail, q->size, q->capacity);
    printf("\n");
}
void enqueue(struct queue *q, struct Data val)
{
    if (q->capacity == q->size) {
        queue_debug(q);
        struct Data *old = q->data;
        q->capacity = q->capacity + q->capacity;
        q->data = malloc(q->capacity * sizeof(struct Data));
        memset(q->data, 0, sizeof(struct Data) * q->capacity);
        memcpy(q->data, old, q->size * sizeof(struct Data));
        free(old);
        printf("queue full extend it\n");
        queue_debug(q);
    }
    q->data[q->tail] = val;
    q->tail++;
    q->size++;
}

int is_queue_empty(struct queue *q)
{
    return q->head == q->tail;
}
static struct Data zero;
struct Data dequeue(struct queue *q)
{
    struct Data temp = q->data[q->head];
    q->data[q->head] = zero;
    q->head++;
    return temp;
}
struct queue * make_queue(int capacity)
{
    struct queue *q = malloc(sizeof(struct queue));
    memset(q, 0, sizeof(struct queue));
    q->capacity = capacity;
    q->data = malloc(q->capacity * sizeof(struct Data));
    memset(q->data, 0, sizeof(struct Data) * q->capacity);
    return q;
}
int main()
{
    struct queue *q = make_queue(5);
    for (int i = 0; i < 10; i++) {
        struct Data temp;
        temp.data = i;
        enqueue(q, temp);
    }
    dequeue(q);
    dequeue(q);
    queue_debug(q);
    for (int i = 5; i < 10; i++) {
        struct Data temp;
        temp.data = i;
        enqueue(q, temp);
    }
    queue_debug(q);
    while(!is_queue_empty(q)) {
        struct Data temp = dequeue(q);
        printf("%d ",temp.data);
    }
    free(q->data);
    free(q);
    printf("\n");
}