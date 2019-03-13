class Solution
{
  public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fiveNum = 0;
        int tenNum = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                fiveNum++;
            }
            else if (bills[i] == 10)
            {
                if (fiveNum < 1)
                {
                    return false;
                }
                else
                {
                    fiveNum--;
                    tenNum++;
                }
            }
            else
            { // 20
                if (fiveNum >= 1 && tenNum >= 1)
                {
                    fiveNum--;
                    tenNum--;
                }
                else if (fiveNum >= 3)
                {
                    fiveNum -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};