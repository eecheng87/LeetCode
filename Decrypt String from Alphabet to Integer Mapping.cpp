class Solution {
public:
    string freqAlphabets(string s) {
        bool single = false;
        int digit_num = 0;
        int cur_id = 0;
        string ans = "";
        for(int j = s.length()-1; j >= 0 ; --j){
            if(digit_num == 2){
                digit_num = 0;
                ans.insert(0,1,cur_id+'a'-1);
                cur_id = 0;
                single = false;
            }
            if(s[j] == '#'){
                single = true;
            }else if(single){
                // multiple digit
                cur_id /= 10;
                cur_id += 10*(s[j]-'0');
                digit_num++;
            }else{
                // just single digit
                ans.insert(0,1,'a'+s[j]-'0'-1);
            }
        }
        if(digit_num == 2){
                ans.insert(0,1,cur_id+'a'-1);
        }
        return ans;
    }
};