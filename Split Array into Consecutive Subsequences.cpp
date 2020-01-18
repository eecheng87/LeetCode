class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count;
        unordered_map<int,int> tail;
        for(int i = 0; i < nums.size(); ++i)
            count[nums[i]]++;
        for(int i = 0; i < nums.size(); ++i){
            if(count[nums[i]] <= 0)
                continue;
            count[nums[i]]--;
            if(tail[nums[i]-1] > 0){
                tail[nums[i]-1]--;
                tail[nums[i]]++;
            }else if(count[nums[i]+1] > 0 && count[nums[i]+2] > 0){
                // at least consecutive three times
                tail[nums[i]+2]++;
                count[nums[i]+2]--;
                count[nums[i]+1]--;
            }else{
                return false;
            }
        }
        return true;
    }
};