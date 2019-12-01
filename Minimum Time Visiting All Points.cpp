class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int ans = 0;
        for (int i = 0; i < points.size() - 1; ++i)
        {
            int a = abs(points[i][1] - points[i + 1][1]);
            int b = abs(points[i][0] - points[i + 1][0]);
            int diag = a > b ? b : a;
            int delta = a > b ? a - b : b - a;
            ans += diag + delta;
        }
        return ans;
    }
};