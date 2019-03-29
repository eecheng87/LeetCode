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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        help(root,ans,3);
        return ans;
    }
    void help(TreeNode* root,int &ans,int state){// 0: left ; 1: right
        if(!root)
            return;
        if(root->left==NULL&&root->right==NULL&&state==0){
            ans+=root->val;
        }
        help(root->left,ans,0);
        help(root->right,ans,1);
    }
};