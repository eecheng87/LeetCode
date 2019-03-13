class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {

        vector<int> ans;

        int carry = 0;
        int last = digits.back() + 1;
        digits.pop_back();
        if (last >= 10)
        {
            last = last % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        ans.insert(ans.begin(), last);

        while (!digits.empty())
        {

            last = digits.back() + carry;
            digits.pop_back();
            if (last >= 10)
            {
                last = last % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            ans.insert(ans.begin(), last);
        }

        if (carry == 1)
            ans.insert(ans.begin(), 1);
        return ans;
    }
};