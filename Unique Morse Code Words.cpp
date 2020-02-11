class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int> mp;
        vector<string> vs = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i = 0; i < words.size(); ++i){
            string tmp = "";
            for(int j = 0; j < words[i].size(); ++j){
                tmp += vs[words[i][j]-'a'];
            }
            mp[tmp]++;
        }
        return mp.size();
    }
};