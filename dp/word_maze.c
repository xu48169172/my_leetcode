#include <stdio.h>
#include <string.h>
#include <malloc.h>
int m;
int n;
int l;
int func(char **s, int i, int j, char *c, int k, int direction)
{
    int up = direction & 0xf;
    int down = direction & 0xf0;
    int left = direction & 0xf00;
    int right = direction & 0xf000;
    int ret;
    if (s[i][j] != c[k])
        return -1;
    if (k == l - 1)
        return 0;
    if (up && (i > 0)) {
        ret =func(s, i - 1, j, c, k + 1, 0x1101);
        if (ret == 0)
            return 0;
    }
    if (down && (i < (m - 1))) {
        ret =func(s, i + 1, j, c, k + 1, 0x1110);
        if (ret == 0)
            return 0;
    }
    if (left && (j > 0)) {
        ret =func(s, i, j - 1, c, k + 1, 0x0111);
        if (ret == 0)
            return 0;
    }
    if (right && (j < (n -1))) {
        ret =func(s, i, j + 1, c, k + 1, 0x1011);
        if (ret == 0)
            return 0;
    }
    return -1;
}
int main()
{
    scanf("%d%d", &m, &n);
    char buf[101];
    memset(buf, 0, 101);
    scanf("%s", buf);
    printf("%s\n", buf);
    l = strlen(buf);
    char **p;
    p = malloc(sizeof(char *) * m);
    for (int i = 0; i < m; i++) {
        *(p + i) = malloc(sizeof(char) * (n + 1));
        memset(*(p + i), 0, sizeof(char) * (n + 1));
    }
    for (int i = 0; i < m; i++) {
            scanf("%s", p[i]);
    }
    printf("====\n");

    for (int i = 0; i < m; i++) {
            printf("%s\n", p[i]);
    }
    int ret;
    for (int i = 0; i < m; i++) {
        for (int j = 0;j < n; j++) {
            ret = func(p, i, j, buf, 0, 0x1111);
            if (ret == 0) {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}