/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        deque<TreeNode*>stack;
        TreeNode* tmp;
        TreeNode* flag;
        if(!root)
            return NULL;
        stack.push_back(root);
        while(!stack.empty()){
            tmp=stack.back();
            stack.pop_back();
            if(tmp->left)
                stack.push_back(tmp->left);
            if(tmp->right)
                stack.push_back(tmp->right);
            // swap
            flag=tmp->right;
            tmp->right=tmp->left;
            tmp->left=flag;
        }
        return root;
    }
};