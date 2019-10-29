#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*

=================================================================
==60482==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000015 at pc 0x7f79ad3f4075 bp 0x7fffadbef4b0 sp 0x7fffadbeec28
READ of size 6 at 0x602000000015 thread T0
    #0 0x7f79ad3f4074  (/usr/lib/x86_64-linux-gnu/libasan.so.4+0x74074)
    #1 0x7f79ad46955f  (/usr/lib/x86_64-linux-gnu/libasan.so.4+0xe955f)
    #2 0x7f79ad3f41ed  (/usr/lib/x86_64-linux-gnu/libasan.so.4+0x741ed)
    #3 0x7f79ad3f4dad in vprintf (/usr/lib/x86_64-linux-gnu/libasan.so.4+0x74dad)
    #4 0x7f79ad3f4e9e in __interceptor_printf (/usr/lib/x86_64-linux-gnu/libasan.so.4+0x74e9e)
    #5 0x55b457f26ef9 in main /home/star/work/code/leetcode/leetcode_5_Longest_Palindromic_Substring.c:50
    #6 0x7f79acfb0b96 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x21b96)
    #7 0x55b457f26b09 in _start (/home/star/work/code/leetcode/a.out+0xb09)

0x602000000015 is located 0 bytes to the right of 5-byte region [0x602000000010,0x602000000015)
allocated by thread T0 here:
    #0 0x7f79ad45eb50 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.4+0xdeb50)
    #1 0x55b457f26dc2 in longestPalindrome /home/star/work/code/leetcode/leetcode_5_Longest_Palindromic_Substring.c:36
    #2 0x55b457f26ee5 in main /home/star/work/code/leetcode/leetcode_5_Longest_Palindromic_Substring.c:50
    #3 0x7f79acfb0b96 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x21b96)

SUMMARY: AddressSanitizer: heap-buffer-overflow (/usr/lib/x86_64-linux-gnu/libasan.so.4+0x74074) 
Shadow bytes around the buggy address:
  0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c047fff8000: fa fa[05]fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==60482==ABORTING

对于字符串buffer， 一定要malloc的时候 多malloc 一个字节 用于存储结束符。 否则后面引用这个buffer 时， 没有结束符 导致 heap buffer overflow
*/
int check_if_palind(char *s, int left, int right)
{
    if (right <= left)
        return -1;
    int len = right - left + 1;
    int i;
    for (i = 0; i < len/2; i++) {
        if (s[left + i] != s[right -i])
            return -1;
    }
    if (i == len/2)
        return 0;
    return -1;
}
char * longestPalindrome(char * s)
{
    int str_len = strlen(s);
    int max_len = 1;
    int most_left = 0;
    int most_right = 0;
    for (int i = 0; i < str_len; i++) {
        for (int j= i+1; j < str_len;j++) {
                if (j - i + 1 <= max_len)
                    continue;
                if (check_if_palind(s, i, j) == 0) {
                    if ((j - i + 1) > max_len) {
                        max_len = j - i + 1;
                        most_left = i;
                        most_right = j;
                    }
                }
        }
    }
    //printf("max_len = %d, most_left=%d, most_right=%d\n",max_len, most_left, most_right);
    char *p = malloc(max_len + 1);
    //printf("%p\n", p);
    memset(p , 0, max_len + 1);
    for (int i = 0; i < max_len; i++) {
        //printf("i=%d, %d\n",i, i + most_left);
        p[i] = s[i + most_left];
    }
    return p;
}
int main()
{
    //char *p = "aba";
    //printf("Hello World:%s\n",longestPalindrome(p));
    char *p = "baabdd";
    printf("Hello World:%s\n",longestPalindrome(p));
    p = "acbbd";
    //printf("Hello World:%s\n",longestPalindrome(p));
}