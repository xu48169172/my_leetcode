#include <string.h>
#include <malloc.h>
#include <string.h>
void erase_all(char *s, char c)
{
    while (*s != '\0') {
        if (*s == c) {
            strcpy(s, s + 1);
        }
        s++;
    }
}
void erase_first(char *s, char c)
{
    while (*s != '\0') {
        if (*s == c) {
            strcpy(s, s + 1);
            break;
        }
        s++;
    }
}
int main()
{
    char *s = "abcdda";
    char *p = malloc(strlen(s) + 1);
    printf("%p\n", p);
    memset(p, 0, strlen(s) + 1);
    strcpy(p, s);
    p[1] = 'c';
    printf("%s\n", p);
    erase_all(p, 'a');
    printf("%s\n", p);
    erase_all(p, 'a');
    printf("%s\n", p);
}