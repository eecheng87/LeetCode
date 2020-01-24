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
    unordered_map<int, int> map;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        for (int i = 0; i < inorder.size(); ++i)
            map[inorder[i]] = i;
        return help(0, 0, inorder.size() - 1, preorder);
    }
    TreeNode *help(int pre_start, int in_start, int in_end, vector<int> &preorder)
    {

        if (in_start > in_end)
            return NULL;

        TreeNode *root = new TreeNode(preorder[pre_start]);
        int index = map[preorder[pre_start]];
        //for(int i = in_start; i <= in_end; ++i)
        //  if(inorder[i] == preorder[pre_start])
        //    index = i;

        root->left = help(pre_start + 1, in_start, index - 1, preorder);

        root->right = help(pre_start + index - in_start + 1, index + 1, in_end, preorder);

        return root;
    }
};