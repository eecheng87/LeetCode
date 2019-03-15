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
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        help(root,-100,-100,ans);
        return ans;
    }
    void help(TreeNode* root,int max,int min,bool &ans){
        if(!root||!ans)
            return;
        if(min!=-100&&root->val<=min)
            ans=false;
        if(max!=-100&&root->val>=max)
            ans=false;
        
        help(root->right,max,root->val,ans);
        help(root->left,root->val,min,ans);
    }
};