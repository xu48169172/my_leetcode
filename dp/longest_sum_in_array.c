#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
    int m, n;
    scanf("%d%d",&m,&n);
    printf("m:%d,n:%d\n", m, n);
    int **p;
    int k, l;
    k = m + 1;
    l = n + 1;
    p = malloc(sizeof(int *) * k);
    for (int i = 0; i < k; i ++)
        *(p + i) = malloc(sizeof(int) * l);
    int **res;
        res = malloc(sizeof(int *) * k);
    for (int i = 0; i < k; i ++) {
        *(res + i) = malloc(sizeof(int) * l);
        memset(*(res + i), 0, sizeof(int) * l);
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d",&p[i][j]);
    
    res[0][0] = p[0][0];
    for (int i = 0; i< m; i++) {
        for (int j = 0; j < n ; j++) {
            if (res[i][j] + p[i + 1][j] > res[i +1][j])
                res[i +1][j] = res[i][j] + p[i + 1][j];
            if (res[i][j] + p[i][j + 1] > res[i][j + 1])
                res[i][j + 1] = res[i][j] + p[i][j + 1];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    printf("Hello World\n");
}