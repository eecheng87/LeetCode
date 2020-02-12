class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> sstack;
        vector<char> tstack;
        for(auto i : S){
            if(i == '#' && !sstack.empty())
                sstack.pop_back();
            else if(i != '#')
                sstack.push_back(i);
        }
        for(auto i : T){
            if(i == '#' && !tstack.empty())
                tstack.pop_back();
            else if(i != '#')
                tstack.push_back(i);            
        }
        /*for(auto i:sstack)
            cout<<i<<" ";
        cout<<endl;
        for(auto i:tstack)
            cout<<i<<" ";*/
        if(sstack.size() != tstack.size())
            return false;
        while(!sstack.empty()){
            if(sstack.back() != tstack.back())
                return false;
            sstack.pop_back();
            tstack.pop_back();
        }
        return true;
    }
};