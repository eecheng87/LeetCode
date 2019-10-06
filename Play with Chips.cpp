class Solution
{
public:
    int minCostToMoveChips(vector<int> &chips)
    {
        int a = 0;
        int b = 0;
        for (auto i : chips)
        {
            if (i % 2 == 0)
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        return min(a, b);
    }
};