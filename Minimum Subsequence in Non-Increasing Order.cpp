class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        
        for(auto i:nums)
            sum += i;
        sort(nums.begin(),nums.end());
        int tmp = 0, start = 0;
        for(int i = nums.size()-1; i >= 0; i--){
            tmp += nums[i];
            if(tmp > sum - tmp){
                start = i;
                break;
            }
        }
        
        vector<int> ans(nums.begin()+start,nums.end());
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};