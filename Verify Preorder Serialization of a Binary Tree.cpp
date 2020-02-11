class Solution {
public:
    bool isValidSerialization(string str) {
        // special case : empty tree
        if(str.size()==1 && str[0] == '#')return true;
        vector<string> stack;
        vector<string> vstr;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ',')
                continue;
            if(str[i] == '#'){
                vstr.push_back("#");
            }else{
                string tmp = "";
                while(i < str.size() && str[i] != ','){
                    tmp = tmp + str[i];
                    i++;
                }
                vstr.push_back(tmp);
                i--;
            }
        }
        for(int i = 0; i < vstr.size(); i++){
            for(auto i:stack)
                        cout<<i<<" ";
            cout<<'\n';
            if(vstr[i][0] == '#'){
                if(stack.empty())
                    return false;
                if(stack.back()[0] != '#'){
                    // top element is digit
                    stack.push_back("#");
                }else{
                    // top is '#'
                    stack.push_back("#");
                    while(stack.size() >= 3 && stack.back()[0] == '#' && stack[stack.size()-2][0] == '#'){
                        stack.pop_back();
                        stack.pop_back();
                        if(stack.back()[0]=='#')return false;
                        stack.pop_back();
                        stack.push_back("#");
                    }
                }
            }else{
                stack.push_back(vstr[i]);
            }
        }
        return stack.size()==1 && stack.front()[0]=='#'?true:false;
    }
};