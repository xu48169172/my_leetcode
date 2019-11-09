#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Data {
    int row;
    int col;
};

struct queue {
    int tail;
    int head;
    struct Data *data;
    int size;
    int capacity;
};
int is_queue_full(struct queue *q)
{
    return q->capacity == q->size;
}
void enqueue(struct queue *q, struct Data key)
{
    if (is_queue_full(q)) {
        printf("queue full\n");
        return;
    }
    q->data[q->tail] = key;
    q->tail++;
    q->size++;
    q->tail = q->tail % q->capacity;
}
int is_queue_empty(struct queue *q)
{
    return q->size == 0;
}
void dequeue(struct queue *q, struct Data *key)
{
    *key = q->data[q->head];
    q->head++;
    q->size--;
    q->head = q->head % q->capacity;
    return;
}
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize)
{
    int **visited = malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        *(visited + i) = malloc(sizeof(int) * gridSize);
        memset(*(visited + i), 0, sizeof(int) * gridSize);
    }
    struct queue *q = malloc(sizeof(struct queue));
    memset(q, 0, sizeof(struct queue));
    q->data = malloc(sizeof(struct Data) * gridSize * gridSize);
    q->capacity = gridSize * gridSize;
    memset(q->data, 0, sizeof(struct Data) * gridSize * gridSize);
    if (!grid[0][0] && !visited[0][0]) {
        struct Data temp;
        temp.row = 0;
        temp.col = 0;
        enqueue(q, temp);
        visited[0][0] = 1;
    }
    while(!is_queue_empty(q)) {
        struct Data key;
        dequeue(q, &key);
        //printf("row:%d, col:%d\n", row, col);
        for (int i = key.row -1; i <= key.row + 1; i++) {
            for (int j = key.col -1; j <= key.col + 1; j++) {
                if (i >=0 && j>=0 && i < gridSize && j < gridSize) {
                    if (!grid[i][j] && !visited[i][j]) {
                        visited[i][j] = visited[key.row][key.col] + 1;
                        struct Data temp;
                        temp.row = i;
                        temp.col = j;
                        enqueue(q, temp);
                        //printf("in: %d, %d\n", i, j);
                    }
                }
            }
        }
    }
    int result = visited[gridSize -1][gridSize -1];
    for (int i = 0; i < gridSize; i++) {
        free(*(visited + i));
    }
    free(visited);
    free(q->data);
    free(q);
    if (result)
        return result;
    else
        return -1;
}
int main()
{
    int gridSize = 3;
    int **grid = malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        *(grid + i) = malloc(sizeof(int) * gridSize);
        memset(*(grid + i), 0, gridSize);
    }
    grid[0][0] = 1;
    grid[0][1] = 0;
    grid[0][2] = 0;

    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[1][2] = 0;

    grid[2][0] = 1;
    grid[2][1] = 1;
    grid[2][2] = 0;

    printf("%d\n", shortestPathBinaryMatrix(grid, gridSize, NULL));
}