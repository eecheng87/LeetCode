class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int mmax = -1;
        bool flag = false;
        sort(satisfaction.begin(), satisfaction.end());
        for (int i = 0; i < satisfaction.size(); i++)
        {
            int index = 1, tmp = 0;
            if (satisfaction[i] > 0)
                flag = true;
            for (int j = i; j < satisfaction.size(); j++)
            {
                tmp += (index++) * satisfaction[j];
            }
            mmax = max(tmp, mmax);
            if (flag)
                break;
        }

        if (mmax < 0)
            return 0;
        else
            return mmax;
    }
};