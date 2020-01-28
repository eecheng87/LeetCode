class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < 0){
                if(nums[abs(nums[i]) - 1] < 0)
                    ans.push_back(abs(nums[i]));
                else
                    nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }else if(nums[nums[i] - 1] < 0){
                //cout<<i<<endl;
                ans.push_back(nums[i]);
            }else{
                nums[nums[i] - 1] = -nums[nums[i] - 1];
            }
        }
        
        //for(auto i:nums)
          //  cout<<i<<endl;
        return ans;
    }
};