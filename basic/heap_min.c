#include <stdio.h>
#include <string.h>
#define PARENT(i) (i/2)
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)
int last = 0;
int buf[10] = {-1};
// 向上保持
void min_heap(int *p, int i)
{
    int parent = PARENT(i);
    int min;
    min = i;
    if (parent >= 1 && p[parent] > p[i])
        min = parent;
    
    if (min != i) {
        int tmp;
        tmp = p[i];
        p[i] = p[min];
        p[min] = tmp;
        min_heap(p, min, data);
    }
}
// 向下保持
void keep(int *p, int i)
{
    int left = LEFT(i);
    int right = RIGHT(i);
    int min = i;
    if (left <=last && p[i] > p[left])
        min = left;
    if (right <= last && p[min] >= p[right])
        min = right;

    if (min != i) {
        int tmp;
        tmp = p[i];
        p[i] = p[min];
        p[min] = tmp;
        keep(p, min);
    }
}
void add(int *p, int data)
{
    last = last + 1;
    p[last] = data;
    min_heap(p, last);
}
void delete(int *p, int data)
{
    int i = 0;
    for (i = 1; i <=last; i++) {
        if (p[i] == data)
            break;
    }
    if (i == last + 1)
        return;
    p[i] = p[last];
    last = last - 1;
    keep(p, i);
    min_heap(p, i);
    return;
}
void query(int *p)
{
    int temp = last;
    int n = 0;
    if (last == 0)
        return;
    
    do {
        n++;
        temp = temp/2;
    } while(temp/2 != 0);
    if (last == 1)
        n = 0;
    for(int i = 0; i <= n; i++) {
        for (int j = 2 * i; j < 2 * 2 * i; j++) {
                if (j == last) {
                    printf("%d", p[j]);
                    break;
                } else if (j == 2 * 2 * i - 1) {
                    printf("%d",p[j]);
                    break;
                } else if (p[j] != -1) {
                    printf("%d ",p[j]);
                }
        }
        if (i == 0)
            printf("%d\n", p[1]);
        else
            printf("\n");
    }

}
int main()
{
    int n,m;
    char cmd[10][10] = {0};
    int temp[10];
    scanf("%d%d", &n, &m);
    for(int i= 0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        add(buf, temp);
    }
    query(buf);
    for(int i = 0; i < m; i++) {
        scanf("%s %d",cmd[i], &temp[i]);
    }
    for(int i = 0; i < m; i++) {
        if (!strcmp(cmd[i], "delete")) {
            delete(buf, temp[i]);
            query(buf);
            printf("\n");
        }
        else if (!strcmp(cmd[i], "add")) {
            add(buf, temp[i]);
            query(buf);
            printf("\n");
        }
    }
    return 0;
}