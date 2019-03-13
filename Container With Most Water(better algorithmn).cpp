class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int front = 0;
        int rear = height.size() - 1;
        int ans = 0;
        while (front < rear)
        {
            ans = max(ans, min(height[front], height[rear]) * (rear - front));
            if (height[front] < height[rear])
                front++;
            else
                rear--;
        }
        return ans;
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
};