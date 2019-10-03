class Solution
{
public:
    bool isValid(string s)
    {
        deque<char> stack;
        int i;
        if (s.size() % 2 == 1)
            return false;
        if (s.size() == 0)
            return true;
        stack.push_back(s[0]);
        for (i = 1; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push_back(s[i]);
            else if (s[i] == ')' && stack.back() == '(')
                stack.pop_back();
            else if (s[i] == '}' && stack.back() == '{')
                stack.pop_back();
            else if (s[i] == ']' && stack.back() == '[')
                stack.pop_back();
            else
                break;
        }
        return stack.empty() ? true : false;
    }
};