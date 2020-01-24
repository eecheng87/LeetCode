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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
                 
        return help(0,0,inorder.size()-1,preorder,inorder);;
    }
    TreeNode* help(int pre_start,int in_start,int in_end,vector<int> preorder, vector<int> inorder){
        //cout<<pre_start<<endl;
        
        if(in_start > in_end ){//|| pre_start > preorder.size()-1){//preorder[pre_start] == inorder[in_start]){
            // leaf
            //cout<<in_start<<endl;
            
            //root->left = NULL;
            //root->right = NULL;
            return NULL;
        }
        TreeNode* root = new TreeNode (preorder[pre_start]);//(TreeNode*)malloc(sizeof(TreeNode));
        
        //cout<<pre_start<<endl;
        //root->val = preorder[pre_start];
        int index = in_start;
        for(int i = in_start; i <= in_end; ++i){
            if(inorder[i] == preorder[pre_start]){
                index = i;
                //i = in_end + 1;
            }
        }
        
        root->left = help(pre_start+1,in_start,index-1,preorder,inorder);
        //cout<<root->val<<endl;
        root->right = help(pre_start+index-in_start+1,index+1,in_end,preorder,inorder);
        
        //cout<<in_start<<in_end<<endl;
        //cout<<root->val<<endl;
        return root;
    }
};