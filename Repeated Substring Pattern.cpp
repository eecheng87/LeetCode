class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string dbl = (s + s).substr(1,s.size()*2 - 2);
        return dbl.find(s) != string::npos? true:false; 
    }
};