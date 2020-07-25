class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = numBottles;
        while (numBottles >= numExchange)
        {
            int more = numBottles / numExchange;
            numBottles = more + numBottles % numExchange;
            ans += more;
        }
        return ans;
    }
};