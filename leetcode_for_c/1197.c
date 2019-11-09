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
void enqueue(struct queue *q, struct Data val)
{
    if (q->capacity == q->size) {
        struct Data *old = q->data;
        q->capacity = q->capacity + q->capacity;
        q->data = malloc(q->capacity * sizeof(struct Data));
        memset(q->data, 0, sizeof(struct Data) * q->capacity);
        memcpy(q->data, old, q->size * sizeof(struct Data));
        free(old);
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
int abs(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}
int minKnightMoves(int x, int y)
{
    x = abs(x);
    y = abs(y);
    int row = y * 2;
    int col = x * 2;
    int start_row = 0;
    int start_col = 0;
    int end_row = y;
    int end_col = x;
    if (x == 0 && y == 0)
        return 0;
    else if (x == 0 && y != 0) {
        row = 4 * y + 20;
        col = 4 * y + 20;
        start_row = row/2;
        start_col = col/2;
        end_row = start_row + y;
        end_col = start_col + x;
    } else if (x != 0 && y == 0) {
        row = 4 * x + 20;
        col = 4 * x + 20;
        start_row = row/2;
        start_col = col/2;
        end_row = start_row + y;
        end_col = start_col + x;
    }  else {
        row = 4 * y + 20;
        col = 4 * x + 20;
        start_row = row/2;
        start_col = col/2;
        end_row = start_row + y;
        end_col = start_col + x;
    }
    int **visited = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        *(visited + i) = malloc(sizeof(int) * col);
        memset(*(visited + i), 0, sizeof(int) * col);
    }
    struct queue *q = make_queue(row * col);
    struct Data temp;
    temp.row = start_row;
    temp.col = start_col;
    enqueue(q, temp);
    visited[start_row][start_col] = 1;
    while (!is_queue_empty(q)) {
        struct Data u = dequeue(q);
        for (int i = -2; i <=2; i = i + 4) {
            for (int j = -1; j <=1; j = j + 2) {
                temp.row = u.row + i;
                temp.col = u.col + j; 
                if (temp.row >= 0 && temp.row < row && temp.col >= 0 && temp.col < col && !visited[temp.row][temp.col]) {
                    enqueue(q, temp);
                    visited[temp.row][temp.col] = visited[u.row][u.col] + 1;
                    if (temp.row == end_row && temp.col == end_col)
                        break; 
                }
                temp.row = u.row + j;
                temp.col = u.col + i;
                if (temp.row >= 0 && temp.row < row && temp.col >= 0 && temp.col < col && !visited[temp.row][temp.col]) {
                    enqueue(q, temp);
                    visited[temp.row][temp.col] = visited[u.row][u.col] + 1;
                    if (temp.row == end_row && temp.col == end_col)
                        break;
                }
            }
        }
    }
    int result = visited[end_row][end_col] - 1;

    for (int i = 0; i < row; i++) {
        free(*(visited + i));
    }
    free(visited);
    free(q->data);
    free(q);
    return result;
}

int main()
{
   printf("%d\n", minKnightMoves(300,0)); 
}
/*
每次移动，他都可以按图示八个方向之一前进。



现在，骑士需要前去征服坐标为 [x, y] 的部落，请你为他规划路线。

最后返回所需的最小移动次数即可。本题确保答案是一定存在的。

 

示例 1：

输入：x = 2, y = 1
输出：1
解释：[0, 0] → [2, 1]
示例 2：

输入：x = 5, y = 5
输出：4
解释：[0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-knight-moves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/