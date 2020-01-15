class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int len = s.length();
        int i = 0;
        int tmp = 0;
        while(i < len){
            if(s[i] == 'R'){
                tmp++;
            }else{
                tmp--;
            }
            i++;
            if(tmp == 0)
                ans++;
        }
        return ans;
    }
};