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
    int maxDepth(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int ans = 0;

        ans = traverse(root);

        return ans;
    }

    int traverse(TreeNode *node)
    {

        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + max(traverse(node->left), traverse(node->right));
        }
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};