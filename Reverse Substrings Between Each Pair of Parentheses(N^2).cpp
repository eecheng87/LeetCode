class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> info;
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                // get how many element in front of '('
                info.push_back(ans.size());
            }else if(s[i]==')'){
                int i = info.back();
                info.pop_back();
                reverse(ans.begin()+i,ans.end());
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};