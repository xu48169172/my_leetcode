#if 0
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
编译选项包含：gcc -g -O0 -fno-omit-frame-pointer -fsanitize=address
#endif
#include <stdio.h>
#include <string.h>
#include <malloc.h>
char * longestPalindrome(char * s)
{
    int len = strlen(s);
    if (len == 1)
        return s;
    int longest = 1;
    int left = 0;
    int right = 0;
    char **dp = malloc(sizeof(int *) * len);
    for (int i = 0 ; i < len; i++) {
        *(dp + i) = malloc(sizeof(char) * len);
        memset(*(dp + i), 0, sizeof(char) * len);
        dp[i][i] = 1;
    }
    int cur_len = 0;
    int r, l;
    for (r = 1; r < len; r++) {
        for (l = 0; l < r; l++) {
            if (s[l] == s[r] &&  (r - l <=2 || dp[l + 1][r -1])) {
                dp[l][r] = 1;
                cur_len = r - l + 1;
                if (cur_len > longest) {
                    longest = cur_len;
                    left = l;
                    right = r;
                }
            }
        }
    }
    char *p = malloc(longest + 1);
    memset(p, 0, longest + 1);
    for (int i = 0; i < longest; i++) {
        p[i] = s[i + left];
    }
    for (int i = 0 ; i < len; i++) {
        free(*(dp + i));
    }
    free(dp);
    return p;
}
int main()
{
    char *s = "cbbd";
    char *r = longestPalindrome(s);
    printf("%s\n", r);
}
