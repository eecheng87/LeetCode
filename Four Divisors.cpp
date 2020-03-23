class Solution {
public:
    int getf(int n){
        int q = sqrt(n), num = 0;
        //cout<<q<<endl;
        vector<int> v;
        if(q*q == n || n <= 5)
            return 0;
        
        for(int i = 1; i < q+1; i++){
            if(n%i == 0){
                v.push_back(i);
                num++;
            }
            if(num>2)
                return 0;
        }
        if(num!=2)
            return 0;
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            ans += v[i] + n/v[i];
        }
       // cout<<n<<" "<<ans<<endl;
        return ans;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += getf(nums[i]);
        }
        return ans;
    }
};