#include <stdio.h>
#include <malloc.h>

void one_dimenisonal_array(void)
{
    int n;
    scanf("%d", &n);
    int *p;
    p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < n; i++)
        printf("%d, ", p[i]);
    printf("\n");
}
void two_dimenisonal_array(void)
{
    int n, m;
    printf("please input n and m\n");
    scanf("%d", &n);
    scanf("%d", &m);
    int **p;
    p = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        *(p + i) = malloc(sizeof(int) * m);
    printf("input array:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j ++)
            scanf("%d", &p[i][j]);
    printf("the input array is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j ++)
            printf("%2d, ", p[i][j]);
        printf("\n");
    }
}
int main()
{
    one_dimenisonal_array();
    two_dimenisonal_array();
    printf("Hello dynamic alloc array\n");
}