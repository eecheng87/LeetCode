class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)
            return false;
        map<char,int> mp;
        int odd = 0, even = 0;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        for(auto x:mp){
            if(x.second % 2 == 0)
                even++;
            else 
                odd++;
        }
        if(odd > k)
            return false;
        return true;
    }
};