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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums,0,nums.size()-1);
    }
    TreeNode* bst(vector<int>&nums,int i,int j){
        if(j-i+1==0)
            return NULL;
        if(j-i+1==1)
            return new TreeNode(nums[i]);
        int mid=(i+j)/2;
        TreeNode* root=new TreeNode(nums[mid]);
  
        root->left=bst(nums,i,mid-1);
        root->right=bst(nums,mid+1,j);
        return root;
    }
};