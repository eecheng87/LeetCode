class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0;
        vector<char> stack;
        for(auto i:S){
            if(i == ')'){
                if(stack.empty()){
                    ans++;
                }else{
                    // top is '('
                    stack.pop_back();
                }
            }else{
                stack.push_back('(');
            }
        }
        return ans + stack.size();
    }
};