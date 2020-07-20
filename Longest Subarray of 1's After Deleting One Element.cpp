class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans = -1;
        int n = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                n++;
                continue;
            }
            int cons = 0;
            bool pre = false;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                {
                    //cout<<i<<" ";
                    continue;
                }
                if (pre && nums[j] == 1)
                {
                    cons++;
                    //cout<<j<<" "<<cons<<"="<<endl;
                }
                else if (nums[j] == 1)
                {
                    cons = 1;
                    pre = true;
                }
                else
                {
                    ans = max(cons, ans);
                    cons = 0;
                    pre = false;
                }
            }
            //cout<<cons<<endl;
            ans = max(cons, ans);
        }
        if (nums.size() == n)
            return n - 1;
        if (nums.size() == n + 1)
            return n;

        return ans;
    }
};