class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int base = 1;
        if(n%2==1){
            // odd
            ans.push_back(0);
            n--;
        }
        
        while(n>0){
            
            ans.push_back(base);
            ans.push_back(-base);
            base++;
            n-=2;
        }        
        return ans;
    }
};