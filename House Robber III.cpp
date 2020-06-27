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
    int *dfs(TreeNode *root)
    {
        if (!root)
        {
            int *arr = new int[2];
            arr[0] = arr[1] = 0;
            return arr;
        }
        int *left = dfs(root->left);
        int *right = dfs(root->right);

        int *res = new int[2];
        res[0] = max(left[0], left[1]) + max(right[0], right[1]); // don't rob current node
        res[1] = root->val + left[0] + right[0];                  // rob current node ( child can't rob )
        return res;
    }
    int rob(TreeNode *root)
    {
        int *ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};