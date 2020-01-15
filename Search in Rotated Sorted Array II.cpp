class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(left <= right){
            mid = (left + right)>>1;
            if(nums[mid] == target)
                return true;
            
            if((nums[mid] == nums[left]) && (nums[mid] == nums[right])){
                left++;
                right--;
            }else if(nums[mid] >= nums[left]){
                // left half is in order
                if(target < nums[mid] && target >= nums[left]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                if(target <= nums[right] && target > nums[mid]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
            
        }
        return false;
    }
};