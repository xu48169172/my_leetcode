#include <stdio.h>
#include <malloc.h>
#include <string.h>

int if_contain_hui(char *str, int left, int right)
{
    int len = strlen(str);
    if (left < 0)
        left = 0;
    for (int i = left + 1; i <= right -1; i++) {
        if (str[i-1] == str[i])
            return i;
        if (str[i] == str[i + 1])
            return i+1;
        if (str[i-1] == str[i+1])
            return i + 1;
    }
    return 0;
}
int main()
{
    int n,p;
    scanf("%d%d", &n, &p);
    char *str = malloc(sizeof(char) * (n + 1));
    scanf("%s", str);
    int right = n - 1;
    char tmp = str[n-1];
    int flag;
    int ret;
    do {
        str[n-1] ++;
        for (int i = n - 1; i >= 1; i--) {
            if (i == right) {
                if (str[right] > tmp) {
                    flag = 1;
                }
            }
            if (str[i] == 'a' + p) {
                str[i] = 'a';
                str[i -1] ++;
            } else {

                break;
            }
        }
        if (str[0] == 'a' + p)
            break;
        if (flag) {
            printf("%s\n",str);
            ret = if_contain_hui(str, right - 2, right);
            if (ret == 0) {                  
                printf("%s,%d\n",str, right);
                return 0;
            }
            right = ret;
            tmp = str[right];
            flag = 0;
            str[right] = str[right] + 1;
            for (int i = right; i >= 1; i--) {
                if (str[i] == 'a' + p) {
                    str[i] = 'a';
                    str[i -1] ++;
                } else {

                    break;
                }
            }
            for (int i = right + 1; i < n; i++)
                str[i] = 'a';
        }

    } while(str[0] <'a' + p);
    printf("NO\n");
}