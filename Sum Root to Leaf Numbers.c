/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sumNumbers(struct TreeNode* root){
    if(!root)return 0;
    int ans = 0;
    dfs(root,&ans,0);
    
    return ans;
}
void dfs(struct TreeNode* cur,int *ans,int curnum){
    if(!cur)return;
    if(!cur->left&&!cur->right){
        *ans+=curnum*10+cur->val;
        //printf("hi");
        return;
    }
    int newcur = curnum*10 + cur->val;
    dfs(cur->left,ans,newcur);
    dfs(cur->right,ans,newcur);
    return;
}