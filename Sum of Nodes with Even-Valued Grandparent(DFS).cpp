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
    int ans = 0;
    int sumEvenGrandparent(TreeNode *root)
    {

        dfs(root, 1, 1);
        return ans;
    }
    void dfs(TreeNode *root, int parent, int grand)
    {

        if (!root)
            return;
        //cout<<root->val<<" "<<parent<<" "<<grand<<endl;
        if (grand % 2 == 0)
            ans += root->val;

        dfs(root->left, root->val, parent);
        dfs(root->right, root->val, parent);
    }
};