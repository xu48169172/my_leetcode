#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define PARENT(i) ((i)/2)
#define LEFT(i) (2 * (i))
#define RIGHT(i) (2 * (i) + 1)
struct Data {
    int data;
};
struct heap {
    int capacity;
    struct Data *data;
    int size;
};
int compare(void *p0, void *p1)
{
    struct Data *a0 = (struct Data *)p0;
    struct Data *a1 = (struct Data *)p1;
    return a0->data - a1->data; // 最小堆
    //return a1->data - a0->data; 最大堆
}
void percolate_up(struct heap *h, int index)
{
    int parent = PARENT(index);
    if (parent >=1 ) {
        if (compare(&h->data[parent], &h->data[index]) > 0) {
            struct Data temp;
            temp = h->data[parent];
            h->data[parent] = h->data[index];
            h->data[index] = temp;
            percolate_up(h, parent);
        }
    }
}
void percolate_down(struct heap *h, int index)
{
    int left = LEFT(index);
    int right = RIGHT(index);
    int min = index;
    if (left <= h->size) {
        if (compare(&h->data[left], &h->data[min]) < 0) {
            min = left;
        }
    }
    if (right <=h->size) {
        if (compare(&h->data[right], &h->data[min]) < 0) {
            min = right;
        }
    }
    if (min != index) {
        struct Data temp;
        temp = h->data[min];
        h->data[min] = h->data[index];
        h->data[index] = temp;
        percolate_down(h, min);
    }
}
static struct Data zero;
struct Data delete_min(struct heap *h)
{
    if (h->size == 0)
        return zero;
    struct Data temp = h->data[1];
    h->data[1] = h->data[h->size];
    h->size--;
    percolate_down(h, 1);
    return temp;
}
void insert(struct heap *h, struct Data key)
{
    h->size++;
    if (h->size == h->capacity) {
        printf("heap full\n");
        return;
    }
    printf("size = %d\n",h->size);
    h->data[h->size] = key;
    percolate_up(h, h->size);
}
void delete(struct heap *h, struct Data key)
{
    for (int i = 1; i <= h->size; i++) {
        if (compare(&h->data[i], &key) == 0) {
            h->data[i] = h->data[h->size];
            h->size--;
            percolate_down(h, i);
            break;
        }
    }
}
void *my_malloc(size_t size)
{
    void *p = malloc(size);
    memset(p, 0, size);
    return p;
}
struct heap* make_heap(int capacity)
{
    struct heap *h = my_malloc(sizeof(struct heap));
    h->capacity = capacity + 1;
    h->data = my_malloc(sizeof(struct Data) * h->capacity);
    h->data[0].data = -1;
    return h;
}
int main()
{
    struct heap *h = make_heap(5);
    struct Data val;
    val.data = 10;
    insert(h, val);
    val.data = 20;
    insert(h, val);
    val.data = 15;
    insert(h, val);
    val.data = 5;
    insert(h, val);
    val.data = 25;
    insert(h, val);

    val.data = 10;
    delete(h, val);
    while (1) {
        struct Data val = delete_min(h);
        if (val.data == 0)
            break;
        printf("%d ", val.data);
    }
    printf("\n");
}