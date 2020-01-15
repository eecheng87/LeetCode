class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int mid = 0;
        int right = nums.size()-1;
        while(left < right){
            mid = (right + left)>>1;
            cout<<mid<<endl;
            if(nums[mid] == target)
                return mid;
            if(nums[right] > nums[mid]){
                // right half is in order
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }else{
                // left half is in order
                if(target < nums[mid] && target >= nums[left]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            } 
        }
        if(right>=0 && nums[left] == target)return left;
        return -1;
    }
};