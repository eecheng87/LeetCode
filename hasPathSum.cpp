/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    bool flag;
    bool hasPathSum(TreeNode *root, int sum)
    {

        int current_sum = 0;
        flag = false;

        if (root == NULL)
            return false;

        traverse(root, current_sum, sum);

        return flag;
    }

    void traverse(TreeNode *node, int current_sum, int sum)
    {

        if (node == NULL)
            return;

        if (current_sum + node->val == sum && node->left == NULL && node->right == NULL)
        {
            flag = true;
        }

        current_sum += node->val;
        traverse(node->left, current_sum, sum);
        traverse(node->right, current_sum, sum);

        if (node->left == NULL && node->right == NULL)
            return;
    }
};