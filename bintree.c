#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct stack {
    int top;
    int *data;
    int capacity;
};
void push(struct stack *p, int val)
{
    if (p->data == NULL) {
        p->data = malloc(sizeof(int) * 128);
        memset(p->data, 0, 128);
        p->capacity = 128;
    }
    if (p->top == p->capacity) {
        int *second;
        second = realloc(p->data, sizeof(int) * 128);
        if (second == NULL) {
            printf("realloc error\n");
            return;
        } else {
            p->data = second;
        }
        p->capacity = p->capacity + 128;
    }
    p->data[p->top] = val;
    p->top++;
}
int pop(struct stack *p)
{
    if (p->top == 0)
        return -1;
    p->top--;
    int temp = p->data[p->top];
    p->data[p->top] = 0;
    return temp;
}
struct stack *sk;
struct TreeNode* build_tree(struct TreeNode *root, int val)
{
    if (root == NULL) {
        root = malloc(sizeof(struct TreeNode));
        root->left = root->right = NULL;
        root->val = val;
        return root;
    } else {
        if (val < root->val) {
            root->left = build_tree(root->left, val);
        } else if (val > root->val)  {
            root->right = build_tree(root->right, val);
        }
    }
    return root;
}
int find_min(struct TreeNode *root)
{
    if (root->left != NULL)
        return find_min(root->left);
    return root->val;
}
int find_max(struct TreeNode *root)
{
    if (root->right != NULL)
        return find_max(root->right);
    return root->val;
}

void pre_order_traverse(struct TreeNode *root)
{
    if (root == NULL)
        return;
    push(sk, root->val);
    pre_order_traverse(root->left);
    pre_order_traverse(root->right);
}
void in_order_traverse(struct TreeNode *root)
{
    if (root == NULL)
        return;
    in_order_traverse(root->left);
    push(sk, root->val);
    in_order_traverse(root->right);
}
void post_order_traverse(struct TreeNode *root)
{
    if (root == NULL)
        return;
    post_order_traverse(root->left);
    post_order_traverse(root->right);
    push(sk, root->val);
}
int main()
{
    struct TreeNode *root = NULL;
    root = build_tree(root, 100);
    root = build_tree(root, 50);
    root = build_tree(root, 60);
    root = build_tree(root, 40);
    root = build_tree(root, 30);
    root = build_tree(root, 45);
    root = build_tree(root, 150);
    root = build_tree(root, 125);
    root = build_tree(root, 175);
    root = build_tree(root, 120);
    root = build_tree(root, 130);
    root = build_tree(root, 170);
    root = build_tree(root, 180);
    sk = malloc(sizeof(struct stack));
    memset(sk, 0, sizeof(struct stack));
    printf("min:%d\n",find_min(root));
    printf("max:%d\n",find_max(root));

    printf("Pre Order Traverse:\n");
    pre_order_traverse(root);
    while(1) {
        int temp = pop(sk);
        if (temp == -1)
            break;
        printf("%d ", temp);
    }
    printf("\n");

    printf("In Order Traverse:\n");
    in_order_traverse(root);
    while(1) {
        int temp = pop(sk);
        if (temp == -1)
            break;
        printf("%d ", temp);
    }
    printf("\n");

    printf("Post Order Traverse:\n");
    post_order_traverse(root);
    while(1) {
        int temp = pop(sk);
        if (temp == -1)
            break;
        printf("%d ", temp);
    }
    printf("\n");
    printf("Hello BinTree\n");
}