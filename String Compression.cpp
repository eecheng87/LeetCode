class Solution {
public:
    int compress(vector<char>& chars) {
        char curc = 1;
        int ans = 0;
        int curnum;
        int n = chars.size();
        for(int i = 0; i < n; i++){
            if(curc != chars[i]){
                int index = i;
                curnum = 0;
                curc = chars[i];
                while(index < n && chars[index] == curc){
                    index++;
                    curnum++;
                }
                
                chars[ans] = curc;
                if(curnum != 1){
                    string carr = to_string(curnum);
                    //cout<<i<<" "<<carr<<endl;
                    int k = 0;
                    for(; k < carr.size(); ++k){
                        chars[ans + k + 1] = carr[k];
                    }
                    ans = ans + k + 1;
                    i = index - 1;  
                }else{
                    ans++;
                }
                
            }
        }
        for(auto a:chars)
            cout<<a<<" ";
        // cout<<ans<<endl;
        return ans;
    }
};