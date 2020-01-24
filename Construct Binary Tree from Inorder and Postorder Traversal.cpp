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
    unordered_map<int,int>map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); ++i)
            map[inorder[i]] = i;
        return help(postorder,postorder.size()-1,0,postorder.size()-1);
    }
    TreeNode *help(vector<int> &postorder,int post_end,int in_start,int in_end){
       
        if(in_end < in_start || post_end < 0)
            return NULL;
        TreeNode *root = new TreeNode(postorder[post_end]);
        int index = map[postorder[post_end]];
        
        root->left = help(postorder,post_end - (in_end - index) -1 ,in_start,index - 1);
        root->right = help(postorder,post_end - 1,index + 1,in_end);
        
        
        return root;
    }
};