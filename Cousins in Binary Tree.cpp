/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool vis_x = false;
    bool vis_y = false;
    int dx, dy;
    TreeNode *px, *py;
    void dfs(TreeNode *root, int &x, int &y, TreeNode *parent, int dep)
    {
        if (!root)
            return;
        if (vis_x && vis_y)
            return;
        if (root->val == x)
        {
            vis_x = true;
            dx = dep;
            px = parent;
        }
        else if (root->val == y)
        {
            vis_y = true;
            dy = dep;
            py = parent;
        }
        dfs(root->left, x, y, root, dep + 1);
        dfs(root->right, x, y, root, dep + 1);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        dfs(root, x, y, NULL, 0);
        if (dx == dy && px != py)
            return true;
        return false;
    }
};
