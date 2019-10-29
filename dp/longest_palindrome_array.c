#include <stdio.h>
#include <string.h>
#include <malloc.h>
// 最长回文序列
void print(char **b, int left, int right, char* x)
{
    if (left == right) {
        printf("%c",x[left]);
        return;
    }
    if (b[left][right] == '-') {
        printf("%d%c",left, x[left]);
        print(b, left +1, right -1, x);
        printf("%d%c",right, x[right]);
    } else if (b[left][right] == 'v') {
        print(b, left +1, right, x);
    } else {
        print(b, left, right - 1, x);
    }
}
int func(char* x, int left, int right, int** c, char **b)
{
    if (left == right)
        return 1;
    if (c[left][right] != 0)
        return c[left][right];
    if (x[left] == x[right]) {
        c[left][right] = func(x, left + 1, right -1, c, b) + 2;
        b[left][right] = '-';
    } else if (func(x, left + 1, right, c, b) >= func(x, left, right -1, c, b)) {
        c[left][right] = func(x, left + 1, right, c, b);
        b[left][right] = 'v';
    } else {
        c[left][right] = func(x, left, right -1, c, b);
        b[left][right] = '<';
    }
    return c[left][right];
}
int main()
{
    char *x = "character";
    int len = strlen(x);
    int **c;
    c = malloc(sizeof(int *) * len);
    for (int i = 0; i < len; i++) {
        *(c+i) = malloc(sizeof(int) * len);
        memset(*(c+i), 0, sizeof(int) * len);
    }
    char **b = malloc(sizeof(char *) * len);
    for (int i = 0; i < len; i++) {
        *(b+i) = malloc(sizeof(char) * len);
        memset(*(b+i), 'n', sizeof(int) * len);
    }
    func(x, 0, len -1, c, b);

    printf("\n");
    for (int i  = 0; i< len; i++) {
        for (int j = 0; j < len; j++)
            printf("%d%c ", c[i][j],b[i][j]);
        printf("\n");
    }
    print(b, 0, len-1, x);
    printf("\nHello longest palindrome array\n");
}