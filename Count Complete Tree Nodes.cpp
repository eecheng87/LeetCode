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
    int countNodes(TreeNode *root)
    {
        int ans = 0;
        count(root, &ans);
        return ans;
    }
    void count(TreeNode *root, int *ans)
    {
        if (root)
        {
            (*ans)++;
            count(root->left, ans);
            count(root->right, ans);
        }
    }
};