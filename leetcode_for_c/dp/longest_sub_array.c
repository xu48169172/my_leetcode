#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 最长公共子序列问题。

// 方法一：自顶向下方法带有记忆的方法， 递归之上，带有记忆
int func(char *x, int m, char *y, int n, int **c, char **b)
{
    if (m < 0 || n < 0)
        return 0;
    if (c[m][n] != 0)
        return c[m][n];
    if (x[m] == y[n]) {
        c[m][n] = func(x, m-1, y, n-1, c, b) + 1;
        b[m][n] = '-';
    }
    else if (func(x, m-1, y, n, c, b) >= func(x, m, y, n-1, c, b)) {
        c[m][n] = func(x, m-1, y, n, c, b);
        b[m][n] = '^';
    } else {
        c[m][n] = func(x, m, y, n-1, c, b);
        b[m][n] = '<';
    }
    return c[m][n]; 
}
// 方法二 自底向上的方法，先计算 f(0) 再计算f(1) 直到 f(n)
void func_2(char *x, int m, char *y, int n, int **c, char **b)
{
    if (x[0] == y[0]) {
        c[0][0] = 1;
        b[0][0] = '-';
    }
    if (x[0] == y[1]) {
        c[0][1] = 1;
        b[0][1] = '-';
    } else if (0 >= c[0][0]) {
        c[0][1] = 0;
        b[0][1] = '^';
    } else {
        c[0][1] = c[0][0];
        b[0][1] = '<';
    }

    if (x[1] == y[0]) {
        c[1][0] = 1;
        b[1][0] = '-';
    } else if (c[0][0] >=0) {
        c[1][0] = c[0][0];
        b[1][0] = '^';
    }

    if (x[1] == y[1]) {
        c[1][1] = c[0][0] + 1;
        b[0][1] = '-';
    } else if (c[0][1] > c[1][0]) {
        c[1][1] = c[0][1];
        b[1][1] = '^';
    } else {
        c[1][1] = c[1][0];
        b[1][1] = '<';
    }

    for (int i = 1; i<m; i++) {
        for (int j = 1; j<n; j++) {
            if (x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = '-';
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = '^';
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = '<';
            }
        }
    }
}
void print_lcs(char **b, int m, int n, char *y)
{
    if (m < 0 || n < 0)
        return;
    if (b[m][n] == '-') {
        print_lcs(b, m-1, n-1, y);
        printf("%c",y[n]);
    } else if  (b[m][n] == '^') {
        print_lcs(b, m-1, n, y);
    } else {
        print_lcs(b, m, n-1, y);
    }
}
int main()
{
    char *x = "RTAWBEFCDEFJK";
    char *y = "QEAQBGHCDGHEFGJWDK";
    int m = strlen(x);
    int n = strlen(y);
    int **c;
    char **b;
    c = malloc(sizeof(int *) * m);
    for (int i = 0; i < n; i++)
        *(c + i) = malloc(sizeof(int) * n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
        }
    }

    b = malloc(sizeof(char *) * m);
    for (int i = 0; i < n; i++)
        *(b + i) = malloc(sizeof(char) * n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = 'N';
        }
    }
    func(x, m-1, y, n-1, c, b);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d%c  ",c[i][j], b[i][j]);
        }
        printf("\n");
    }
    print_lcs(b, m-1, n-1, y);
    printf("\nmethod 2\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = 'N';
        }
    }
    func_2(x, m, y, n, c, b);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d%c  ",c[i][j], b[i][j]);
        }
        printf("\n");
    }
    print_lcs(b, m-1, n-1, y);
    printf("\nHello longest sub array\n");
}