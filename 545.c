#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct queue {
    int tail;
    int *data;
    int block_size;
    int size;
};
void enqueue(struct queue *q, int val)
{
    if (q->data == NULL) {
        q->size = q->block_size = 128;
        q->data = malloc(q->size * sizeof(int));
        
    }
    if (q->tail == q->size) {
        q->size = q->size + q->block_size;
        int *second = realloc(q->data, q->size * sizeof(int));
        if (second == NULL) {
            printf("realloc error\n");
        } else {
            q->data = second;
        }
    }
    q->data[q->tail] = val;
    q->tail++;
}
int is_leaf(struct TreeNode* root)
{
    return root->left == NULL && root->right == NULL;
}
void find_min(struct TreeNode* root, struct queue *q)
{
    if (root == NULL)
        return;
    if (!is_leaf(root))
        enqueue(q, root->val);
    if (root->left)
        find_min(root->left, q);
    else
        find_min(root->right, q);
}
void pre_order_traverse(struct TreeNode* root, struct queue *q)
{
    if (is_leaf(root)) {
        enqueue(q, root->val);
    }
    if (root->left)
        pre_order_traverse(root->left, q);
    if (root->right)
        pre_order_traverse(root->right, q);
}
struct stack {
    int top;
    int block_size;
    int *data;
    int size;
};
void push(struct stack *p, int val)
{
    if (p->data == NULL) {
        p->size = p->block_size = 128;
        p->data = malloc(p->size * sizeof(int));
    }
    if (p->top == p->size) {
        p->size = p->size + p->block_size;
        int *second = realloc(p->data, p->size * sizeof(int));
        if (second == NULL) {
            printf("realloc stack error\n");
            return;
        } else {
            p->data = second;
        }
    }
    p->data[p->top] = val;
    p->top++;
}
int is_empty(struct stack *p)
{
    return p->top == 0;
}
int pop(struct stack *p)
{
    p->top--;
    return p->data[p->top];
}
void find_max(struct TreeNode *root, struct stack *p)
{
    if (root == NULL)
        return;
    if (!is_leaf(root))
        push(p, root->val);
    
    if (root->right)
        find_max(root->right, p);
    else 
        find_max(root->left, p);
}
int* boundaryOfBinaryTree(struct TreeNode* root, int* returnSize)
{
    struct queue *q = calloc(1, sizeof(struct queue));
    struct stack *p = calloc(1, sizeof(struct stack));
    *returnSize = 0;
    if (root == NULL)
        return NULL;
    if (!is_leaf(root))
        enqueue(q, root->val);
    find_min(root->left, q);
    pre_order_traverse(root, q);
    find_max(root->right, p);
    while (!is_empty(p)) {
        enqueue(q, pop(p));
    }
    *returnSize = q->tail;
    return q->data;
}

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
int main()
{
    struct TreeNode *root = NULL;
    root = build_tree(root, 1);
    root = build_tree(root, 3);
    root = build_tree(root, 2);
    root = build_tree(root, 4);
    int returnSize = 0;
    int *out = boundaryOfBinaryTree(root, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
}

#if 0
给定一棵二叉树，以逆时针顺序从根开始返回其边界。边界按顺序包括左边界、叶子结点和右边界而不包括重复的结点。 (结点的值可能重复)

左边界的定义是从根到最左侧结点的路径。右边界的定义是从根到最右侧结点的路径。若根没有左子树或右子树，则根自身就是左边界或右边界。注意该定义只对输入的二叉树有效，而对子树无效。

最左侧结点的定义是：在左子树存在时总是优先访问，如果不存在左子树则访问右子树。重复以上操作，首先抵达的结点就是最左侧结点。

最右侧结点的定义方式相同，只是将左替换成右。

示例 1

输入:
  1
   \
    2
   / \
  3   4

输出:
[1, 3, 4, 2]

解析:
根不存在左子树，故根自身即为左边界。
叶子结点是3和4。
右边界是1，2，4。注意逆时针顺序输出需要你输出时调整右边界顺序。
以逆时针顺序无重复地排列边界，得到答案[1,3,4,2]。
 

示例 2

输入:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
输出:
[1,2,4,7,8,9,10,6,3]

解析:
左边界是结点1,2,4。(根据定义，4是最左侧结点)
叶子结点是结点4,7,8,9,10。
右边界是结点1,3,6,10。(10是最右侧结点)
以逆时针顺序无重复地排列边界，得到答案 [1,2,4,7,8,9,10,6,3]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/boundary-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#endif