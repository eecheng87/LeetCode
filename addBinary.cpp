class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        int sum=0;
        if(i>j){
            while(i!=j){
                b="0"+b;
                j++;
            }
        }else if(i<j){
            while(i!=j){
                a="0"+a;
                i++;
            }
        }
        i=a.length()-1;
        j=b.length()-1;
  
        while(i>=0 && j>=0){
            if(a[i]=='1'&&b[j]=='1'){
                if(carry==0){
                    carry=1;
                    ans="0"+ans;
                }else{
                    carry=1;
                    ans="1"+ans;
                }
            }else if((a[i]=='0'&&b[j]=='1')||(a[i]=='1'&&b[j]=='0')){
                if(carry==0){
                    carry=0;
                    ans="1"+ans;
                }else{
                    carry=1;
                    ans="0"+ans;
                }
            }else{
                if(carry==0){
                    carry=0;
                    ans="0"+ans;
                }else{
                    carry=0;
                    ans="1"+ans;
                }
            }
            i--;
            j--;
        }
        if(carry<1)
            return ans;
        return "1"+ans;
    }
};