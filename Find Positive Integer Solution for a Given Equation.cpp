/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution
{
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
    {
        vector<vector<int>> ans;
        for (int x = 1; x <= 1000; ++x)
        {

            int left = 1;
            int right = 1001;
            int mid;
            while (left < right)
            {
                mid = (left + right) / 2;
                if (z > customfunction.f(x, mid))
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
            if (customfunction.f(x, left) == z)
            {
                ans.push_back({x, left});
            }
        }
        return ans;
    }
};