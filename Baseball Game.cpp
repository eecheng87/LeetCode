class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> stack;
        int ans = 0;
        int tmp;
        for (int i = 0; i < ops.size(); ++i)
        {
            //cout<<"A";
            if (ops[i] == "C")
            {
                ans -= stack.back();
                stack.pop_back();
            }
            else if (ops[i] == "D")
            {
                tmp = stack.back() * 2;
                ans += tmp;
                stack.push_back(tmp);
            }
            else if (ops[i] == "+")
            {
                tmp = stack[stack.size() - 1] + stack[stack.size() - 2];
                ans += tmp;
                stack.push_back(tmp);
            }
            else
            {
                ans += stoi(ops[i]);
                stack.push_back(stoi(ops[i]));
            }
        }
        return ans;
    }
};