class Solution {
public:
    int countSegments(string s) {
        s = ' ' + s;
        int ans = 0;
        for(int i = 0; i < s.size() - 1; ++i){
            if(s[i] == ' ' && s[i+1] != ' '){
                ans++;
            }
        }
        return ans;
    }
};