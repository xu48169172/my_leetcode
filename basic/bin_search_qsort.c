#include <stdio.h>
#include <stdlib.h>

int binary_search(int *out, int key, int num)
{
    int left = 0;
    int right = num - 1;
    int flag = 0;
    if (num == 0)
        return flag;
    if (key < out[left] || key > out[right])
        return flag;
    while (left <= right) {
        int mid = (right + left)/2;
        if (key < out[mid]) {
            right = mid - 1;
        } else if (key > out[mid]) {
            left = mid + 1;
        } else {
            flag = 1;
            break;
        }
    }
    return flag;
}
int compare(const void *p0, const void *p1)
{
    int a0 = *(int *)p0;
    int a1 = *(int *)p1;
    return a0- a1;
}

int main()
{
    int a[]= {10, 8, 6, 15, 14, 4};
    qsort(a, sizeof(a)/sizeof(a[0]), sizeof(int), compare);
    for (int i = 0; i < sizeof(a)/sizeof(a[0]);i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("find result:%d\n",binary_search(a, 10, sizeof(a)/sizeof(a[0])));
    printf("find result:%d\n",binary_search(a, 9, sizeof(a)/sizeof(a[0])));
}