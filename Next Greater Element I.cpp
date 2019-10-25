class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> stack(nums1.begin(), nums1.end());
        vector<int> ans;
        int m;
        while (!stack.empty())
        {
            m = -10000;
            for (int i = nums2.size() - 1; i >= 0; --i)
            {
                if (stack.front() == nums2[i])
                {
                    if (m < 0)
                        ans.push_back(-1);
                    else
                        ans.push_back(m);
                    stack.erase(stack.begin());
                    break;
                }
                else if (nums2[i] > stack.front())
                {
                    m = nums2[i];
                }
            }
        }
        return ans;
    }
};