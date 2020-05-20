class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            tmp = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                tmp ^= arr[j];
                if (tmp == 0)
                {
                    ans += (j - i);
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        return ans;
    }
};