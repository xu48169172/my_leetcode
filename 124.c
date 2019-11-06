#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int is_leaf(struct TreeNode* root)
{
    return root->left == NULL && root->right == NULL;
}
int max = -1000000;
int post_order_traverse(struct TreeNode *root)
{
    if (is_leaf(root))
        return root->val;
    int left = 0;
    int right = 0;
    if (root->left) {
        left = post_order_traverse(root->left);
        if (left > max)
            max = left;
    }
    if (root->right) {
        right= post_order_traverse(root->right);
        if (right > max)
            max = right;
    }
    if (root->val > max)
        max = root->val;
    int sum_node = root->val + left + right;
    if (sum_node > max)
        max = sum_node;
    int left_max = root->val + left;
    if (left_max > max)
        max = left_max;
    int right_max = root->val + right;
    if (right_max > max)
        max = right_max;
    int edge_max = left_max > right_max ? left_max : right_max;
    root->val = edge_max > root->val ? edge_max : root->val;
    return root->val;
}
int maxPathSum(struct TreeNode* root){
    max = -1000000;
    int ret = post_order_traverse(root);
    return max > ret ? max : ret;
}

int main()
{

}