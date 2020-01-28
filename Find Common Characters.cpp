class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        vector<int> cnt(26,100000);
        for(int i = 0; i < A.size(); ++i){
            vector<int> tmp(26,0);
            for(int j = 0; j < A[i].size(); j++){
                tmp[A[i][j] - 'a']++;
            }
            for(int j = 0; j < cnt.size(); ++j){
                cnt[j] = min(cnt[j],tmp[j]);
            }
        }
        for(int i = 0; i < cnt.size(); ++i){
            while(cnt[i] > 0){
                ans.push_back(string(1,'a' + i));
                cnt[i]--;
            }
        }
        return ans;
    }
    
};