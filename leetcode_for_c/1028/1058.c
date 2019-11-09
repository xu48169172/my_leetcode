#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 两种思路写法都可以解决问题。
// 结算每一个值的 floor error 和 ceil error。 计算最小值和最大值 以及中间值
// 如果target > mid  则说明 取ceil 比较多， 如果target < mid. 则说明floor 比较多。
// 用贪心的原理，取误差最小。target > mid 取ceil 误差 最小
// target < mid 取floor 误差最小
struct Node {
    long ceil_error;
    long floor_error;
    long val;
};
int compare_floor(void *p0, void *p1)
{
    struct Node *u = (struct Node *)p0;
    struct Node *v = (struct Node *)p1;
    if (u->floor_error < v->floor_error)
        return -1;
    else
        return 1;  
}
int compare_ceil(void *p0, void *p1)
{
    struct Node *u = (struct Node *)p0;
    struct Node *v = (struct Node *)p1;
    if (u->ceil_error < v->ceil_error)
        return -1;
    else
        return 1;  
}
char * minimizeError(char ** prices, int pricesSize, int target)
{
    printf("pricesSize=%d\n",pricesSize);
    struct Node *nodes = malloc(sizeof(struct Node) * pricesSize);
    memset(nodes, 0, sizeof(struct Node) * pricesSize);
    long min = 0;
    long max = 0;
    long out_min = 0;
    long out_max = 0;
    long zero = 0;
    for (int i = 0; i < pricesSize; i++) {
        long floor;
        long ceil;
        char *price = prices[i];
        long x = atoi(&price[strlen(price) - 3]);
        long z = atoi(price);
        nodes[i].val = z;
        if (x > 0) {
            ceil = z + 1;
        } else {
            ceil = z;
        }
        nodes[i].floor_error = x;
        nodes[i].ceil_error = (ceil - z) * 1000 - x;
        min = min + z;
        max = max + ceil;
        out_min = out_min + nodes[i].floor_error;
        out_max = out_max + nodes[i].ceil_error;
        if (x == 0) {
            printf("%s\n", price);
            zero++;
        }
        //printf("%ld, %ld, %ld\n", nodes[i].val, nodes[i].floor_error, nodes[i].ceil_error);
    }
    printf("%ld, %ld\n", min, max);
    char *outbuf = malloc(10);
    memset(outbuf, 0, 10);
    if (target < min || target > max) {
        sprintf(outbuf, "%d", -1);
        free(nodes);
        return outbuf;
    } else if (min == target) {
        sprintf(outbuf, "%.3f", (float)out_min/1000);
        free(nodes);
        return outbuf;
    } else if (max == target) {
        sprintf(outbuf, "%.3f", (float)out_max/1000);
        free(nodes);
        return outbuf;
    }
    int mid = (max - min)/2 + min;
    printf("%ld\n", mid);
    long out = 0;
    if (target >= mid) {
        qsort(nodes, pricesSize, sizeof(struct Node), compare_ceil);
        int i = 0;
        for (i = zero; i < target - min + zero; i++) {
            out = out + nodes[i].ceil_error;
        }
        for (int j = i; j < pricesSize; j++) {
            out = out + nodes[j].floor_error;
        }
        
    } else {// 6 7 8 9
        qsort(nodes, pricesSize, sizeof(struct Node), compare_floor);
        int i = 0;
        for (i = zero; i < max - target + zero; i++) {
            out = out + nodes[i].floor_error;
        }
        for (int j = i; j < pricesSize; j++) {
            out = out + nodes[j].ceil_error;
        }
    }
    if (out == 0)
        sprintf(outbuf, "%d", -1);
    else
        sprintf(outbuf, "%.3f", (float)out/1000);
    free(nodes);
    return outbuf;
}
int main()
{
    char **temp = malloc(sizeof(char *) * 4);
    *(temp) = "0.700";
    *(temp + 1) = "2.800";
    *(temp + 2) = "4.900";
    *(temp + 3) = "3.000";
    char *output = minimizeError(temp, 4, 10);
    printf("%s\n", output);

}
#if 0
struct Node {
    float ceil_error;
    float floor_error;
    float val;
};
int compare_floor(void *p0, void *p1)
{
    struct Node *u = (struct Node *)p0;
    struct Node *v = (struct Node *)p1;
    if (u->floor_error < v->floor_error)
        return -1;
    else
        return 1;  
}
int compare_ceil(void *p0, void *p1)
{
    struct Node *u = (struct Node *)p0;
    struct Node *v = (struct Node *)p1;
    if (u->ceil_error < v->ceil_error)
        return -1;
    else
        return 1;  
}
char * minimizeError(char ** prices, int pricesSize, int target)
{
    struct Node *nodes = malloc(sizeof(struct Node) * pricesSize);
    memset(nodes, 0, sizeof(struct Node) * pricesSize);
    float min = 0;
    float max = 0;
    float out_min = 0;
    float out_max = 0;
    float zero = 0;
    for (int i = 0; i < pricesSize; i++) {
        float floor;
        float ceil;
        nodes[i].val = atof(prices[i]);
        floor = (float)((int)(nodes[i].val));
        min = min + floor;
        if (nodes[i].val > floor) {
            ceil = (float)((int)(nodes[i].val) + 1);
        } else {
            ceil = floor;
            zero++;
        }
        max = max + ceil;
        nodes[i].floor_error = nodes[i].val - floor;
        nodes[i].ceil_error = ceil - nodes[i].val;
        out_min = out_min + nodes[i].floor_error;
        out_max = out_max + nodes[i].ceil_error;
        //printf("%f, %f, %f\n", nodes[i].val, nodes[i].floor_error, nodes[i].ceil_error);
    }
    //printf("%f, %f\n", min, max);
    char *outbuf = malloc(10);
    memset(outbuf, 0, 10);
    if (target < min || target > max) {
        sprintf(outbuf, "%d", -1);
        free(nodes);
        return outbuf;
    } else if (min == target) {
        sprintf(outbuf, "%.3f", out_min);
        free(nodes);
        return outbuf;
    } else if (max == target) {
        sprintf(outbuf, "%.3f", out_max);
        free(nodes);
        return outbuf;
    }
    int mid = (max - min)/2 + min;
    float out = 0;
    if (target >= mid) {
        qsort(nodes, pricesSize, sizeof(struct Node), compare_ceil);
        int i = 0;
        for (i = zero; i < target - min + zero; i++) {
            out = out + nodes[i].ceil_error;
        }
        for (int j = i; i < pricesSize; i++) {
            out = out + nodes[i].floor_error;
        }
        
    } else {// 6 7 8 9
        qsort(nodes, pricesSize, sizeof(struct Node), compare_floor);
        int i = 0;
        for (i = zero; i < max - target + zero; i++) {
            out = out + nodes[i].floor_error;
        }
        for (int j = i; i < pricesSize; i++) {
            out = out + nodes[i].ceil_error;
        }
    }
    if (out == 0)
        sprintf(outbuf, "%.3f", (float)-1);
    else
        sprintf(outbuf, "%.3f", out);
    free(nodes);
    return outbuf;
}
#endif
#if 0
0 2 4 5
1 3 5 6
1 2 4 5 = 0.3 0.8 0.9 0.3 = 2.3
0 3 4 5 = 0.7 0.2 0.9 0.3 = 2.1
0 2 5 5 = 0.7 0.8 0.1 0.3 = 1.9
0 2 4 6 = 0.7 0.8 0.9 0.7 = 3.1
给定一系列价格 [p1,p2...,pn] 和一个目标 target，将每个价格 pi 舍入为 Roundi(pi) 以使得舍入数组 [Round1(p1),Round2(p2)...,Roundn(pn)] 之和达到给定的目标值 target。每次舍入操作 Roundi(pi) 可以是向下舍 Floor(pi) 也可以是向上入 Ceil(pi)。

如果舍入数组之和无论如何都无法达到目标值 target，就返回 -1。否则，以保留到小数点后三位的字符串格式返回最小的舍入误差，其定义为 Σ |Roundi(pi) - (pi)|（ i 从 1 到 n ）。

 

示例 1：

输入：prices = ["0.700","2.800","4.900"], target = 8
输出："1.000"
解释： 
使用 Floor，Ceil 和 Ceil 操作得到 (0.7 - 0) + (3 - 2.8) + (5 - 4.9) = 0.7 + 0.2 + 0.1 = 1.0 。
示例 2：

输入：prices = ["1.500","2.500","3.500"], target = 10
输出："-1"
解释：
达到目标是不可能的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-rounding-error-to-meet-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#endif
