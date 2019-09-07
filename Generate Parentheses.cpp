class Solution {
public:
    vector<string> generateParenthesis(int n) {
       
        vector<string>ans;

        help(ans,"",0,0,n);
         
        return ans;
    }
    void help(vector<string>&ans,string tmp,int left,int right,int n){
        if(tmp.size()==n*2){
            ans.push_back(tmp);
            return;
        }else if(left>=right&&left<n){
            help(ans,tmp+"(",left+1,right,n);
            help(ans,tmp+")",left,right+1,n);
        }else if(left>=right){ 
            help(ans,tmp+")",left,right+1,n);
        }
    }
                 
};