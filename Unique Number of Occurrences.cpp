class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<int> v(arr.size(), -1);
        int tmp;
        int time = 1;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                time++;
            }
            else
            {
                if (v[time] < 0)
                {
                    v[time] = 1;
                }
                else
                {
                    return false;
                }
                time = 1;
            }
        }
        if (arr[arr.size() - 1] != arr[arr.size() - 2] && v[time] > 0)
            return false;
        return true;
    }
};