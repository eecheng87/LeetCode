class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=sum+nums[i]>nums[i]?sum+nums[i]:nums[i];
            ans=ans<sum?sum:ans;
        }
        return ans;
    }
};