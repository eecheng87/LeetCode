class Solution {
public:
    bool ispara(string s){
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n - 1 - i])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.empty())
            return 0;
        else if(ispara(s))
            return 1;
        else 
            return 2;
    }
};