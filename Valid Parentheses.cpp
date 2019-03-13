class Solution
{
  public:
    bool isValid(string s)
    {
        deque<char> stack;
        if (s.length() % 2 != 0)
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stack.push_back(s[i]);
            }
            else
            {
                if (stack.empty())
                    return false;
                if (s[i] == ')' && stack.back() != '(')
                    return false;
                if (s[i] == '}' && stack.back() != '{')
                    return false;
                if (s[i] == ']' && stack.back() != '[')
                    return false;
                stack.pop_back();
            }
        }

        return stack.empty() ? true : false;
    }
};