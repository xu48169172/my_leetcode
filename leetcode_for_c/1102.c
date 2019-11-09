#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define PARENT(i) ((i)/2)
#define LEFT(i) (2 * (i))
#define RIGHT(i) (2 * (i) + 1)
struct Data {
    int i;
    int j;
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
    //return a0->data - a1->data; // 最小堆
    return a1->data - a0->data; //最大堆
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
int is_heap_empty(struct heap *h)
{
    return h->size == 0;
}
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
        printf("heap full, %d %d\n",h->size, h->capacity);
        return;
    }
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

int **malloc_array(int row, int col)
{
    int **visited = my_malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        *(visited + i) = my_malloc(sizeof(int) * col);
    }
    return visited;
}

int maximumMinimumPath(int** A, int ASize, int* AColSize)
{
    printf("%d , %d\n", ASize, AColSize[0]);
    struct heap *h = make_heap(ASize * AColSize[0] * 10);
    int **visited = malloc_array(ASize, AColSize[0]);
    struct Data temp;
    temp.i = 0;
    temp.j = 0;
    temp.data = A[temp.i][temp.j];
    visited[0][0] = 1;
    insert(h, temp);
    int directions[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    int min = A[0][0] < A[ASize - 1][AColSize[0] -1] ?  A[0][0] : A[ASize - 1][AColSize[0] - 1];
    while (!is_heap_empty(h)) {
        temp = delete_min(h);
        //printf("%d, %d, %d\n", temp.i, temp.j, temp.data);
        for (int i = 0; i < 4; i++) {
            int new_i = temp.i + directions[i][0];
            int new_j = temp.j + directions[i][1];
            if (new_i >=0 && new_i < ASize && new_j >=0 && new_j < AColSize[0] && !visited[new_i][new_j]) {
                //printf("%d, %d\n", new_i, new_j);
                if (temp.data < min)
                    min = temp.data;
                if (new_i == ASize - 1 && new_j == AColSize[0] - 1)
                    return min;
                visited[new_i][new_j] = 1;
                struct Data new;
                new.i = new_i;
                new.j = new_j;
                new.data = A[new.i][new.j];
                insert(h, new);
            }
        }
    }
    return min;
}
int main()
{
    
}
/*
给你一个 R 行 C 列的整数矩阵 A。矩阵上的路径从 [0,0] 开始，在 [R-1,C-1] 结束。

路径沿四个基本方向（上、下、左、右）展开，从一个已访问单元格移动到任一相邻的未访问单元格。

路径的得分是该路径上的 最小 值。例如，路径 8 →  4 →  5 →  9 的值为 4 。

找出所有路径中得分 最高 的那条路径，返回其 得分。

 

示例 1：



输入：[[5,4,5],[1,2,6],[7,4,6]]
输出：4
解释： 
得分最高的路径用黄色突出显示。 
示例 2：



输入：[[2,2,1,2,2,2],[1,2,2,2,1,2]]
输出：2
示例 3：



输入：[[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
输出：3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-maximum-minimum-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/