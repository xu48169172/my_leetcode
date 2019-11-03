#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Manhattan(int *p0, int *p1)
{
    int sumx = p0[0] > p1[0] ? (p0[0] - p1[0]) : (p1[0] - p0[0]); 
    int sumy = p0[1] > p1[1] ? (p0[1] - p1[1]) : (p1[1] - p0[1]);
    return sumx + sumy;
}
struct work_bike {
    int index;
    int m;
};
int compare(void *p0, void *p1)
{
    struct work_bike *w0 = (struct work_bike *)p0;
    struct work_bike *w1 = (struct work_bike *)p1;
    if (w0->m == w1->m) {
        return w0->index - w1->index;
    } else {
        return w0->m - w1->m;
    }
}
int* assignBikes(int** workers, int workersSize, int* workersColSize, int** bikes, int bikesSize, int* bikesColSize, int* returnSize)
{
    struct work_bike **wm = malloc(sizeof(struct work_bike *) * workersSize);
    int *worker_visited = malloc(sizeof(int) * workersSize);
    for (int i = 0 ; i < workersSize; i++) {
        *(wm + i) = malloc(sizeof(struct work_bike) * bikesSize);
        for (int j = 0; j < bikesSize; j++) {
            wm[i][j].index = j;
            wm[i][j].m = Manhattan(workers[i], bikes[j]);
        }
        qsort(wm[i], bikesSize, sizeof(struct work_bike), compare);
        worker_visited[i] = 0;
    }
#if 0
    for (int i = 0; i < workersSize; i++) {
        for (int j = 0; j < bikesSize; j++)
            printf("worker:%d, bike: %d, m:%d\n", i, wm[i][j].index, wm[i][j].m);
    }
#endif
    struct work_bike **bm = malloc(sizeof(struct work_bike *) * bikesSize);
    int *bike_visited = malloc(sizeof(int) * bikesSize);
    for (int i = 0 ; i < bikesSize; i++) {
        *(bm + i) = malloc(sizeof(struct work_bike) * workersSize);
        for (int j = 0; j < workersSize; j++) {
            bm[i][j].index = j;
            bm[i][j].m = Manhattan(bikes[i], workers[j]);
        }
        qsort(bm[i], workersSize, sizeof(struct work_bike), compare);
        bike_visited[i] = 0;
    }
#if 0
    for (int i = 0; i < bikesSize; i++) {
        for (int j = 0; j < workersSize; j++)
            printf("bike:%d, worker: %d, m:%d\n", i, bm[i][j].index, bm[i][j].m);
    }
#endif
    int *out = malloc(sizeof(int) * workersSize);
    for (int i = 0; i < workersSize; i++) {
        out[i] = -1;
    }
    int count = 0;
    while (count < workersSize) {
        for (int i = 0; i < workersSize; i++) {
            if (!worker_visited[i]) {
                int select_bike = 0;
                for (int j = 0; j < bikesSize; j++) {
                    if(!bike_visited[wm[i][j].index]) {
                        select_bike = wm[i][j].index;
                        break;
                    }
                }
                int select_worker = 0;
                for (int k = 0; k < workersSize; k++) {
                    if(!worker_visited[bm[select_bike][k].index]) {
                        select_worker = bm[select_bike][k].index;
                        break;
                    }
                }
                //printf("%d, %d, %d\n", i, select_bike, select_worker);
                if ( i == select_worker) {
                    worker_visited[select_worker] = 1;
                    bike_visited[select_bike] = 1;
                    out[i] = select_bike;
                    count++;
                }
            }
        }
    }
    *returnSize = workersSize;
    for (int i = 0 ; i < workersSize; i++) {
        free(*(wm + i));
    }
    free(wm);
    free(worker_visited);
    for (int i = 0 ; i < bikesSize; i++) {
        free(*(bm + i));
    }
    free(bm);
    free(bike_visited);
    return out;
}

#define WORKERSIZE 3
#define WORKERCOlSIZE 2
#define BIKESIZE 3
#define BIKECOLSIZE 2
int main()
{
    int returnSize = 0;
    int **workers = malloc(sizeof(int *) * WORKERSIZE);
    for (int i = 0; i < WORKERSIZE; i++) {
        *(workers + i) = malloc(sizeof(int) * WORKERCOlSIZE);
        memset(*(workers + i), 0, sizeof(int) * WORKERCOlSIZE);
    }
    workers[0][0] = 0;
    workers[0][1] = 0;
    workers[1][0] = 1;
    workers[1][1] = 1;
    workers[2][0] = 2;
    workers[2][1] = 0;
    int *workersColSize = malloc(sizeof(int) * WORKERSIZE);
    for (int i = 0; i < WORKERSIZE; i++) {
        workersColSize[i] = WORKERCOlSIZE;
    }

    int **bikes = malloc(sizeof(int *) * BIKESIZE);
    for (int i = 0; i < BIKESIZE; i++) {
        *(bikes + i) = malloc(sizeof(int) * BIKECOLSIZE);
        memset(*(bikes + i), 0, sizeof(int) * BIKECOLSIZE);
    }
    bikes[0][0] = 1;
    bikes[0][1] = 0;
    bikes[1][0] = 2;
    bikes[1][1] = 2;
    bikes[2][0] = 2;
    bikes[2][1] = 1;
    int *bikesColSize = malloc(sizeof(int) * BIKESIZE);
    for (int i = 0; i< BIKESIZE; i++) {
        bikesColSize[i] = BIKECOLSIZE;
    }
    int *p = assignBikes(workers, WORKERSIZE, workersColSize, bikes, BIKESIZE, bikesColSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ",p[i]);
    }
    printf("\n");
    printf("Hello assignBikes\n");
}

#if 0
在由 2D 网格表示的校园里有 n 位工人（worker）和 m 辆自行车（bike），n <= m。所有工人和自行车的位置都用网格上的 2D 坐标表示。

我们需要为每位工人分配一辆自行车。在所有可用的自行车和工人中，我们选取彼此之间曼哈顿距离最短的工人自行车对  (worker, bike) ，并将其中的自行车分配給工人。如果有多个 (worker, bike) 对之间的曼哈顿距离相同，那么我们选择工人索引最小的那对。类似地，如果有多种不同的分配方法，则选择自行车索引最小的一对。不断重复这一过程，直到所有工人都分配到自行车为止。

给定两点 p1 和 p2 之间的曼哈顿距离为 Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|。

返回长度为 n 的向量 ans，其中 a[i] 是第 i 位工人分配到的自行车的索引（从 0 开始）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/campus-bikes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

输入：workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
输出：[1,0]
解释：
工人 1 分配到自行车 0，因为他们最接近且不存在冲突，工人 0 分配到自行车 1 。所以输出是 [1,0]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/campus-bikes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

输入：workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
输出：[0,2,1]
解释：
工人 0 首先分配到自行车 0 。工人 1 和工人 2 与自行车 2 距离相同，因此工人 1 分配到自行车 2，工人 2 将分配到自行车 1 。因此输出为 [0,2,1]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/campus-bikes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#endif