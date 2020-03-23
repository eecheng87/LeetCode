class Solution {
public:
    static int getP(int num){
        int ans = 0;
        int t = num;
        while(t != 1){
            if(t%2==0){
                t=t/2;
            }else{
                t=t*3+1;
            }
            ans++;
        }
        return ans;
    }
    static bool cmp(int &a, int &b){
        int pa = getP(a);
        int pb = getP(b);
        if(pa != pb)
            return pa < pb;
        else 
            return a < b;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> v(hi-lo+1,0);
        for(int i = 0; i < v.size(); i++)
            v[i] = lo + i;
        sort(v.begin(),v.end(),cmp);
        return v[k-1];
    }
};