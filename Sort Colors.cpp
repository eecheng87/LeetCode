class Solution {
public:
    void sortColors(vector<int>& nums) {
        int tmp;
        int low = 0, high = nums.size()-1, mid = 0;
        while(mid <= high){
            if(nums[mid] == 0){
                // swap low and mid
                tmp = nums[mid];
                nums[mid] = nums[low];
                nums[low] = tmp;
                mid++;
                low++;
            }else if(nums[mid] == 1){
                // actually is at mid
                mid++;
            }else if(nums[mid] == 2){
                // swap high and mid
                tmp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = tmp;
                high--;
            }
        }
    }
};