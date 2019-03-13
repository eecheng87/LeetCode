class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        std::vector<int>::iterator it;
        if (nums.empty())
            return nums.size();
        while (find(nums.begin(), nums.end(), val) != nums.end() && nums.size() != 0)
        {
            nums.erase(find(nums.begin(), nums.end(), val));
        }
        if (nums.back() == val)
        {
            nums.erase(nums.end());
        }
        //cout<<nums.size();
        return nums.size();
    }
};