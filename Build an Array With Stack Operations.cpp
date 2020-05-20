class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;
        int i = 1;
        for (int index = 0; index < target.size();)
        {
            if (target[index] == i)
            {
                ans.push_back("Push");
                index++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++;
        }

        return ans;
    }
};