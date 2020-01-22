class Solution {
public:
    vector<string> printVertically(string s) {
        int max = -1;
        istringstream iss(s);
        string str;
        vector<string> sv;
        while(getline(iss,str,' ')){
            // max = max < str.length()?max:str.length();
            // cout<<str.size()<<" "<<max<<endl;
            int len = str.size();
            if(len > max)
                max = len;
                
            sv.push_back(str);
        }
        
        vector<string> ans(max,"");
        vector<bool> start(max,false);
        for(int i = sv.size()-1; i >= 0; --i){
            for(int j = 0; j < max; ++j){
                if(max <= sv[i].size()){
                    ans[j] = sv[i][j] + ans[j];
                    start[j] = true;
                }else if(start[j] && sv[i].size() <= j){
                    ans[j] = " " + ans[j];
                }else if(sv[i].size() > j){
                    ans[j] = sv[i][j] + ans[j];
                    start[j] = true;
                }
            }
        }
        return ans;
    }
};