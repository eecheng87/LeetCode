class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,int> ms;
        for(auto i:s){
            ms[i]++;
        }
        for(auto i:t){
            ms[i]--;
            if(ms[i]<0)
                return false;
        }
        return true;
    }
};