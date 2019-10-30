#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 通过了测试但是逻辑复杂有点
struct stack {
    int top;
    int prio;
    char *p;
};
int get_priority(char s)
{
    if (s == '+' || s == '-')
        return 1;
    else if (s == '*' || s == '/')
        return 2;
    else
        return 0;
}
void push(struct stack *sk, char c)
{
    sk->p[sk->top] = c;
    sk->top++;
    sk->prio = get_priority(c);
}
int is_empty(struct stack *sk)
{
    return sk->top == 0;
}
char pop(struct stack *sk)
{
    if (is_empty(sk))
        return '0';
    sk->top--;
    char c = sk->p[sk->top];
    sk->p[sk->top] = (char)0;
    if (sk->top > 0)
        sk->prio = get_priority(sk->p[sk->top - 1]);
    else 
        sk->prio = 0;
    return c;
}
struct stack1 {
    int top;
    long *p;
};
void push1(struct stack1 *sk, unsigned long c)
{
    sk->p[sk->top] = c;
    sk->top++;
}
int is_empty1(struct stack1 *sk)
{
    return sk->top == 0;
}
long pop1(struct stack1 *sk)
{
    if (is_empty1(sk))
        return -1;
    sk->top--;
    long c = sk->p[sk->top];
    sk->p[sk->top] = 0;
    return c;
}
int check(char s)
{
    if (s == '+' || s == '-' || s== '*' || s == '/')
        return 1;
    else
        return 0;
}
int calculate(char * s)
{
    int len = strlen(s);
    struct stack *sk = malloc(sizeof(struct stack));
    memset(sk, 0, sizeof(struct stack));
    sk->p = malloc(len);
    memset(sk->p, 0, len);
    char **s1 = malloc((len + 1) * sizeof(char *));
    memset(s1, 0, (len + 1) * sizeof(char *));
    int k = 0;
    while (*s != '\0') {
        char temp = s[0];
        if(temp >= '0' && temp <= '9') {
            char *ptr;
            unsigned long data = strtoul(s, &ptr, 0);
            s = ptr;
            ptr = malloc(50);
            memset(ptr, 0, 50);
            sprintf(ptr, "%lu", data);
            s1[k] = ptr;
            k++;
        } else if (check(temp)) {
            s++;
            int prio = get_priority(temp);
            int cur_prio = sk->prio;
            if (prio > cur_prio) {
                push(sk, temp);
            } else {
                while (1) {
                    char f = pop(sk);
                    if (f == '0')
                        break;
                    if (get_priority(f) >= prio) {
                        char *ptr = malloc(2);
                        memset(ptr, 0, 2);
                        s1[k] = ptr;
                        k++;
                        ptr[0] = f;
                    }
                    if (sk->prio < prio) {
                        break;
                    }
                }
                push(sk, temp);
            }
        } else {
            s++;
            continue;
        }
    }
    while (1) {
        char f = pop(sk);
        if (f == '0')
            break;
        char *ptr = malloc(2);
        memset(ptr, 0, 2);
        s1[k] = ptr;
        k++;
        ptr[0] = f;
    }
    for (int i = 0; i < k; i++) {
        printf("%s", s1[i]);
    }
    printf("\n");
    struct  stack1 *sk1 = malloc(sizeof(struct stack1));
    memset(sk1, 0, sizeof(struct stack1));
    sk1->p = malloc(sizeof(long) * k);
    for (int i = 0; i < k; i++)
    {
        if (s1[i][0] == '*') {
            long a0 = pop1(sk1);
            long a1 = pop1(sk1);
            push1(sk1, a1*a0);
        } else if (s1[i][0] == '/') {
            long a0 = pop1(sk1);
            long a1 = pop1(sk1);
            push1(sk1, a1/a0);
        } else if (s1[i][0] == '+') {
            long a0 = pop1(sk1);
            long a1 = pop1(sk1);
            push1(sk1, a1+a0);
        } else if (s1[i][0] == '-') {
            long a0 = pop1(sk1);
            long a1 = pop1(sk1);
            push1(sk1, a1-a0);           
        } else {
            push1(sk1, atol(s1[i]));
        }
    }
    return pop1(sk1);
}

int main()
{

    char *s = " 32 * 10 /10 - 10 +5 / 2 * 4 /2";
    printf("Hello World %d\n", calculate(s));
}
#if 0
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:

输入: "3+2*2"
输出: 7
示例 2:

输入: " 3/2 "
输出: 1
示例 3:

输入: " 3+5 / 2 "
输出: 5
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#endif