class Solution {
public:
    int reverse(int x) {
        bool pos=x>0?true:false;
        long long ans=0;
        long long tmp=x>0?x:(long long)x*(-1);
       
        while(tmp>=10){
            ans+=tmp%10;
            tmp/=10;
            ans*=10; 
        }
        ans+=tmp;
        if(tmp>0&&ans>INT_MAX)
            return 0;
        if(tmp<0&&ans<INT_MIN)
            return 0;
        return pos?ans:-ans;
    }
};