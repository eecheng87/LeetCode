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
    vector<int>list1;
    vector<int>list2;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        int i = 0;
        int j = 0;
        traverse(root1,list1);
        traverse(root2,list2);
        while(i<list1.size()&&j<list2.size()){
            if(list1[i]<list2[j]){
               ans.push_back(list1[i]);
                i++;
            }else{
                ans.push_back(list2[j]);
                j++;
            }
        }
        if(i<list1.size()){
            while(i<list1.size()){
                ans.push_back(list1[i]);
                i++;
            }
        }else{
            while(j<list2.size()){
                ans.push_back(list2[j]);
                j++;
            }            
        }
        return ans;
    }
    void traverse(TreeNode* root,vector<int>&li){
        if(root){
            traverse(root->left,li);
            li.push_back(root->val);
            traverse(root->right,li);
        }
    }
};