class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int tmp = 1;
        char p = s[0];
        for(int i = 1; i < s.size(); i ++){
            if(s[i] == p){
                tmp++;
            }else{
                tmp = 1;
                p = s[i];
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};