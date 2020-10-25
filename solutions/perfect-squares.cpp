//Perfect Squares -> 08/30/2020 11:50
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
 
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int tmin=INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                if(dp[i-j*j]+1<tmin)
                    tmin=dp[i-j*j]+1;
            }
            dp[i]=tmin;
        }
        return dp[n];
    }
};
