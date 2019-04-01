class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int front = 0;
        int end = nums.size() - 1;
        int ans;
        while (true)
        {
            int pivot = partition(nums, front, end);
            if (pivot < nums.size() - k)
            {
                front = pivot + 1;
            }
            else if (pivot > nums.size() - k)
                end = pivot - 1;
            else
            {
                ans = nums[pivot];
                break;
            }
        }

        return ans;
    }

    int partition(vector<int> &arr, int front, int end)
    {
        int tmp;
        // select pivot
        int pivot = arr[end];
        // i is a flag point that place which should swap
        int i = front - 1;
        for (int j = front; j < end; j++)
        {
            if (arr[j] < pivot)
            {
                // swap
                i++;
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
        i++;
        tmp = arr[end];
        arr[end] = arr[i];
        arr[i] = tmp;
        return i;
    }
};