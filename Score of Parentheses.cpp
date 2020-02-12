class Solution {
public:
    int scoreOfParentheses(string S) {
        // '(' means -1 in stack
        S = "(" + S + ")";
        vector<int> stack;
        for(int i = 0; i < S.size(); ++i){
            if(S[i] == '('){
                stack.push_back(-1);
            }else{
                if(stack.back() < 0){
                    // top is '('
                    stack.pop_back();
                    stack.push_back(1);
                }else{
                    int tmp = 0;
                    while(stack.back() > 0){
                        tmp += stack.back();
                        stack.pop_back();
                    }
                    // pop '('
                    stack.pop_back();
                    stack.push_back(tmp * 2);
                }
            }
        }
        return stack.back()/2;
    }
};
