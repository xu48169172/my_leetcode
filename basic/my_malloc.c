#include <stdio.h>
#include <malloc.h>
#include <string.h>

void *my_malloc(size_t size)
{
    void *p = malloc(size);
    memset(p, 0, size);
    return p;
}
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void build_tree()
{

}
int main()
{
    int a[][4] = {{1, 2, 3, 4},{5, 6, 7, 8}};
    int row = sizeof(a)/sizeof(a[0]);
    int **p = malloc(sizeof(int *) * row);
    for (int i = 0; i< row; i++) {
        *(p + i) = malloc(sizeof(int) * 4);
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 4; j++) {
            p[i][j] = a[i][j];
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}
