#include <stdio.h>
#include <string.h>
#if 0
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

 

示例 1：

输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：

输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
示例 3：

输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入："/a/./b/../../c/"
输出："/c"
示例 5：

输入："/a/../../b/../c//.//"
输出："/c"
示例 6：

输入："/a//b////c/d//././/.."
输出："/a/b/c"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplify-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#endif
// 如果前后各补一个/  判断的条件会变简单。
struct stack {
    int top;
    char *data;
};
void push(struct stack *p, char s)
{
    p->data[p->top] = s;
    p->top++;
}
int is_empty(struct stack *p)
{
    return p->top == 0;
}
char pop(struct stack *p)
{
    if(p->top == 0)
        return 0;
    p->top--;
    char temp = p->data[p->top];
    p->data[p->top] = 0;
    return temp;
}
char head(struct stack *p)
{
    if (is_empty(p))
        return 0;
    return p->data[p->top - 1];
}
char * simplifyPath(char * path)
{
    struct stack *p = malloc(sizeof(struct stack));
    memset(p, 0, sizeof(struct stack));
    p->data = malloc(strlen(path) + 1);
    memset(p->data, 0, strlen(path) + 1);
    char *t = malloc(strlen(path) + 1 + 2);
    char *t1 = t;
    memset(t, 0, strlen(path) + 1 + 2);
    t[0] ='/';
    strncpy(t + 1, path, strlen(path));
    t[strlen(path) + 1] = '/';
    while (*t != '\0') {
        //printf("%s\n", p->data);
        if (head(p) == '/') {
            if (!strncmp(t, "/", 1)) {
                t = t + 1;
            } else if (!strncmp(t, "./", 2)) {
                t = t + 2;
            } else if (!strncmp(t, "../", 3)) {
                pop(p);
                t = t + 3;
                while (1) {
                    char temp = pop(p);
                    if (temp == '/' || is_empty(p)) {
                        push(p, '/');
                        break;
                    }
                }
            } else {
                push(p, *t);
                t = t + 1;
            }
        } else if (*t == '/') {
            push(p, *t);
            if (!strncmp(t + 1, "/", 1)) {
                t = t + 2;
            } else if (!strncmp(t + 1, "./", 2)) {
                t = t + 3;
            } else if (!strncmp(t + 1, "../", 3)) {
                pop(p);
                t = t + 4;
                while (1) {
                    char temp = pop(p);
                    if (temp == '/' || is_empty(p)) {
                        push(p, '/');
                        break;
                    }
                }
            } else {
                t = t + 1;
            }
        } else {
            if (head(p) != '/')
                push(p, *t);
            t++;
        }
    }
    if (p->top > 1)
        pop(p);
    free(t1);
    return p->data;
}
#if 0
char * simplifyPath(char * path)
{
    struct stack *p = malloc(sizeof(struct stack));
    memset(p, 0, sizeof(struct stack));
    p->data = malloc(strlen(path) + 1);
    memset(p->data, 0, strlen(path) + 1);
    p->data[0] = '/';
    p->top = 1;
    //printf("len = %d\n", strlen(path));
    for (int i = 0; i < strlen(path); i++) {
        //printf("%s\n",p->data);
        if (path[i] == '.') {
            if (((i == strlen(path) -1) || (path[i + 1] == '/')) && (p->data[p->top - 1] == '/')) {
                i++;
                continue;
            } else if ((path[i + 1] == '.') && (p->data[p->top - 1] == '/') && (path[i + 2] == '/' || i + 1 == strlen(path) -1)) {
                i++;
                i++;
                int count;
                pop(p);
                while(1) {
                    char temp = pop(p);
                    if (temp == 0)
                        break;
                    if (temp == '/') {
                        push(p, '/');
                        break;
                    }
                }
            } else {
                push(p, path[i]);
            }
        } else if (path[i] == '/') {
            if (path[i + 1] == '/') {
                continue;
            } else if (path[i + 1] == '.' && (i + 1 == (strlen(path) -1))) {
                i++;
                continue;
            } else {
                if (p->data[p->top - 1] == '/')
                    continue;
                push(p, path[i]);
            }
        } else {
           push(p, path[i]); 
        }
    }
    if (p->top != 1 && p->data[p->top - 1] == '/')
        pop(p);
    return p->data;
}

#endif


int main()
{
    char *s = NULL;
  
    s = "/a..";
    printf("%s\n", simplifyPath(s));

    s = "/a//b////c/d//././/..";
    printf("%s\n", simplifyPath(s));

    s = "/a/../../b/../c//.//";
    printf("%s\n", simplifyPath(s));

    s = "/./yPvI/./X/../cCwm/../../.";
    printf("%s\n", simplifyPath(s));

    s = "/home//foo/";
    printf("%s\n", simplifyPath(s));

    s = "/../";
    printf("%s\n", simplifyPath(s));

    s = "/home/";
    printf("%s\n", simplifyPath(s));

    s = "/abc/../././../a/.";
    printf("%s\n", simplifyPath(s));

    s = "/abc/../././../a/";
    printf("%s\n", simplifyPath(s));

    s = "/abc/../././../a";
    printf("%s\n", simplifyPath(s));

    s = "/abc/.././../a";
    printf("%s\n", simplifyPath(s));

    s = "/abc/../";
    printf("%s\n", simplifyPath(s));

    s = "/abc/..";
    printf("%s\n", simplifyPath(s));

    s = "./abc";
    printf("%s\n", simplifyPath(s));

    s = "../abc";
    printf("%s\n", simplifyPath(s));

    s = "/abc/../../ab";
    printf("%s\n", simplifyPath(s));

}