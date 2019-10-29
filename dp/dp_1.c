#include <stdio.h>
#include <string.h>
#include <malloc.h>

int src[100][100];
int res[100][100];
// 方法1 与方法2 都是向下遍历， 缺点最后还需要再遍历一次。但是在动态规划的范畴都是属于自底向上的遍历方法。
int  method_1(int n)
{
    int i, j;
// method one
    for (i = 0; i < n; i ++)
        res[0][i] = src[0][i];
    for (i = 1; i < n; i++) {
        for (int j=0;j < n; j++) {
            if (src[i][j] == -1)
                continue;
            if (j-1 < 0)
                res[i][j] = src[i][j] + res[i-1][j-1+1];
            else if (res[i-1][j -1 + 1] == -1)
                res[i][j] = src[i][j]+ res[i-1][j-1];
            else 
                res[i][j] = src[i][j] + (res[i-1][j-1] > res[i-1][j-1+1] ? res[i-1][j-1]:res[i-1][j-1+1]);
        }
    }
    int max = -1;
    for (j = 0; j < n; j++)
        if (res[n-1][j] > max)
            max = res[n-1][j];
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d, ",res[i][j]);
        }
        printf("\n");
    }
    return max;
}
int method_2(int n)
{
    int i, j;
// method one
    for (i = 0; i < n; i ++)
        res[0][i] = src[0][i];
    for (i = 0; i < n-1; i++) {
        for (int j=0;j <=i; j++) {
            if ((res[i][j] + src[i + 1][j]) > res[i + 1][j])
                res[i + 1][j] = res[i][j] + src[i + 1][j];
            if ((res[i][j] + src[i + 1][j + 1]) > res[i + 1][j + 1])
                res[i + 1][j + 1] = res[i][j] + src[i + 1][j + 1];
        }
    }
    int max = -1;
    for (j = 0; j < n; j++)
        if (res[n-1][j] > max)
            max = res[n-1][j];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d, ",res[i][j]);
        }
        printf("\n");
    }
    return max;
}

// 从下往上遍历更简单
int method_3(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        res[n-1][i] = src[n-1][i];
    for (i = n -2; i >=0; i--) {
        for (int j=0;j <=i; j++) {
            res[i][j] = (res[i+1][j] + src[i][j]) > (src[i][j] + res[i+1][j+1]) ? (res[i+1][j] + src[i][j]): (src[i][j] + res[i+1][j+1]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d, ",res[i][j]);
        }
        printf("\n");
    }
    return res[0][0];
}
int main()
{
    int i,j;
    int n = 0;
    scanf("%d",&n);
    printf("n:%d\n", n);
    
    for (i = 0; i< n; i++) {
        for(j = 0; j<=i; j++) {
            scanf("%d",&src[i][j]);
        }
    }
   

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d, ",src[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Hello Dynamic Programing, max = %d\n", method_1(n));
    printf("Hello Dynamic Programing, max = %d\n", method_2(n));
    printf("Hello Dynamic Programing, max = %d\n", method_3(n));
}