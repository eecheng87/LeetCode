class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int front = 0;
        int rear = nums.size() - 1;
        int mid = (int)((front + rear) / 2);

        while (1)
        {
            if (target == nums[mid])
                return mid;
            if (target > nums[mid])
            {
                front = mid;
                mid = (front + rear) / 2;
            }
            if (target < nums[mid])
            {
                rear = mid;
                mid = (front + rear) / 2;
            }

            if (front == mid || mid == rear)
                if (nums[front] == target)
                    return front;
                else if (nums[rear] == target)
                    return rear;
                else
                    return -1;
        }
    }
};