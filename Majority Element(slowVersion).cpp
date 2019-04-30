class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0;
        quickSort(nums,0,nums.size()-1);

        return nums[nums.size()/2];
    }
    void quickSort(vector<int> &num,int front,int end){
        if(front<end){
            int pivot = partition(num,front,end);
            quickSort(num,front,pivot-1);
            quickSort(num,pivot+1,end);
        }
    }
    int partition(vector<int>&num,int front,int end){
        int tmp;
        int pivot = num[end];
        int i = front-1;
        for(int j = front; j < end; j++){
            if(num[j]<pivot){
                i++;
                tmp = num[j];
                num[j] = num[i];
                num[i] = tmp;
            }
        }
        i++;
        tmp = num[end];
        num[end] = num[i];
        num[i] = tmp;
        return i;
    }
};