class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
    void quickSort(vector<int> &arr, int front, int end)
    {
        if (front < end)
        {
            int pivot = partition(arr, front, end);
            quickSort(arr, front, pivot - 1);
            quickSort(arr, pivot + 1, end);
        }
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