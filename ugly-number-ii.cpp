//Ugly Number II -> 08/30/2020 22:24
class Solution {
public:
    int nthUglyNumber(int n) {
         int ugly[n+1];
        ugly[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<=n;i++){
            int x=min(ugly[i2]*2,min(ugly[i3]*3,ugly[i5]*5));
            ugly[i]=x;
            if(x==ugly[i2]*2) i2++;
            if(x==ugly[i3]*3) i3++;
            if(x==ugly[i5]*5) i5++;
        }
        return ugly[n-1];
    }
};
