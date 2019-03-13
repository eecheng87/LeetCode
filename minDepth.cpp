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
    int minDepth(TreeNode *root)
    {
        int min = 100000;
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;

        help(root, 0, &min);
        return min;
    }
    void help(TreeNode *root, int cur, int *min)
    {

        if (!root)
            return;

        cur++;
        // encount leaf node
        if (!root->left && !root->right)
        {
            if (cur < *min)
                *min = cur;
        }

        help(root->left, cur, min);
        help(root->right, cur, min);
    }
};