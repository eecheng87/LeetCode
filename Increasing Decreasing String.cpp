class Solution {
public:
    string sortString(string s) {
        string ans;
        vector<int> v(26,0);
        int j;
        for(int i = 0; i < s.size(); i++){
            v[s[i]-'a']++;
        }
        while(ans.size() != s.size()){
            j = 0;
            while(j < 26){
                if(v[j] > 0){
                    ans.push_back(j+'a');
                    v[j]--;
                }          
                j++;
            }
            if(ans.size() == s.size())
                break;
            j = 25;
            while(j >= 0){
                 if(v[j] > 0){
                    ans.push_back(j+'a');
                    v[j]--;
                }                 
                j--;
            }
        }
        return ans;
    }
};