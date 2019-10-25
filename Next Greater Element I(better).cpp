class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> stack;
        vector<int> ans;
        unordered_map<int, int> map;
        if (nums2.empty() || nums1.empty())
            return ans;
        stack.push_back(nums2[0]);
        for (int i = 1; i < nums2.size(); ++i)
        {
            if (nums2[i] > stack.back())
            {
                while (!stack.empty() && stack.back() < nums2[i])
                {
                    map[stack.back()] = nums2[i];
                    stack.pop_back();
                }
                stack.push_back(nums2[i]);
            }
            else
            {
                stack.push_back(nums2[i]);
            }
        }
        for (int j = 0; j < nums1.size(); ++j)
        {
            if (!map.count(nums1[j]))
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(map[nums1[j]]);
            }
        }
        return ans;
    }
};