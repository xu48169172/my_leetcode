#if 0
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#endif
#include <stdio.h>
#include <string.h>
#if 0 // 因为memset超时
int lengthOfLongestSubstring(char * s)
{
    int temp[256];
    memset(temp, 0, 256 * sizeof(int));
    int max = 0;
    int sum = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (!temp[s[i]]) {
            sum++;
            temp[s[i]] = i + 1;
        } else {
            if (sum > max) {
                max = sum;
            }
            i = temp[s[i]] - 1;
            sum = 0;
            memset(temp, 0, 256 * sizeof(int));
        }
    }
    if (sum > max) {
        max = sum;
    }
    return max;
}
#endif
int lengthOfLongestSubstring(char * s)
{
    int temp[256];
    memset(temp, 0, 256 * sizeof(int));
    int max = 0;
    int sum = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (left < temp[s[i]])
            left = temp[s[i]];
        right++;
        temp[s[i]] = right;
        if ((right - left) > max) {
            max = right - left;
        }

    }
    return max;
}
int main()
{
    //char *s = "abacd";
    char *s = "pwwkew";
    printf("%d\n", lengthOfLongestSubstring(s));
}