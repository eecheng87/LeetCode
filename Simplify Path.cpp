class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> stack;
        string ans;
        stringstream ss(path);
        string tok;
        while (getline(ss, tok, '/'))
        {
            if (tok == ".." && !stack.empty())
            {
                stack.pop_back();
            }
            else if (tok.empty() || tok == "." || tok == "..")
            {
                continue;
            }
            else
            {
                stack.push_back(tok);
            }
        }
        while (!stack.empty())
        {
            ans += '/' + stack.front();
            stack.erase(stack.begin());
        }
        return ans.empty() ? "/" : ans;
    }
};