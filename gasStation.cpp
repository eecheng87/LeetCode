class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        for (int i = 0; i < gas.size(); i++)
        {
            if (gas[i] < cost[i])
                continue;
            int j = i;
            int current = gas[i];
            while (1)
            {
                if (current - cost[j % gas.size()] >= 0)
                {
                    current -= cost[j % gas.size()];
                    j++;
                    current += gas[j % gas.size()];
                }
                else
                {
                    i = j;
                    break;
                }
                if (j % gas.size() == i)
                    return i;
            }
        }

        return -1;
    }
};