class Solution {
public:
    int ans = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        dfs(nums,0,0,S);
        return ans;
    }
    void dfs(vector<int>& nums,int start,int cur,int target){
        if(start == nums.size()){
            if(cur == target){
                ans++;
            }
            return;
        }
            
        
        dfs(nums, start + 1, cur + nums[start], target);
        dfs(nums, start + 1, cur - nums[start], target);
    }
};