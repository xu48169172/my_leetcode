#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
struct Data {
    int data;
};
struct stack {
    int top;
    struct Data *data;
    int size;
    int capacity;
};
void push(struct stack *p, struct Data *val)
{
    if (p->top == p->capacity) {
        p->capacity = p->capacity + p->capacity;
        struct Data *old = p->data;
        p->data = malloc(p->capacity * sizeof(struct Data));
        memset(p->data, 0, p->capacity * sizeof(struct Data));
        memcpy(p->data, old, p->top * sizeof(struct Data));
        free(old);
        printf("stack full, extend it\n");
    }
    p->data[p->top] = *val;
    p->top++;
}
int is_stack_empty(struct stack *p)
{
    return p->top == 0;
}
static struct Data zero;
struct Data pop(struct stack *p)
{
    p->top--;
    struct Data val = p->data[p->top];
    p->data[p->top] = zero;
    return val;
}
struct stack* make_stack(int capacity)
{
    struct stack *p = malloc(sizeof(struct stack));
    memset(p, 0, sizeof(struct stack));
    p->capacity = capacity;
    p->data = malloc(p->capacity * sizeof(struct Data));
    memset(p->data, 0, p->capacity * sizeof(struct Data));
    return p;
}
int main()
{
    struct stack *p = make_stack(5);
    for (int i = 0; i < 20; i++) {
        struct Data temp;
        temp.data = i;
        push(p, &temp);
    }
    while (!is_stack_empty(p)) {
        struct Data temp = pop(p);
        printf("%d ",temp.data);
    }
    free(p->data);
    free(p);
    printf("\n");
}