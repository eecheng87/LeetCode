#include <math.h>
class Solution
{
  public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        vector<int> l1;
        vector<int> l2;
        int N;
        N = pow(2, n);

        if (n == 0)
        {
            ans.push_back(0);
            return ans;
        }

        l1.push_back(0);
        l1.push_back(1);

        for (int i = 0; i < n - 1; i++)
        {
            l2.clear();
            for (int j = 0; j < l1.size(); j++)
            { //reverse l1 to l2
                l2.insert(l2.begin(), l1[j] + (1 << (i + 1)));
            }

            for (int k = 0; k < l2.size(); k++)
            { //merge l2 to l1
                l1.push_back(l2[k]);
            }
        }

        return l1;
    }
};