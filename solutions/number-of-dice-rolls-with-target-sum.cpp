//Number of Dice Rolls With Target Sum</a -> 08/23/2020 15:51
class Solution {
// #define m 1000000007
// int dp(int d, int f, int target, int sum, map<pair<int, int>, int>& cache)
// {
//     if(d == 0 && sum == 0)
//         return 1;
//     if(d == 0 && sum != 0)
//         return 0;
//     if(cache.find(make_pair(d, sum)) != cache.end())
//         return cache[make_pair(d, sum)];
//     int ans = 0;
//     for(int i = 1; i <= f; i++)
//     {
//         if(target - i >= d - 1)
//         {
//             ans = ans % m + dp(d - 1, f, target, sum - i, cache) % m;
//         }
//     }
//     return cache[make_pair(d, sum)] = ans % m;
// }
public:
    int numRollsToTarget(int d, int f, int target) {
        // map<pair<int, int>, int> cache;
        // return dp(d, f, target, target, cache);
        vector<vector<int>> dp(d+1, vector<int>(target+1, 0));
        int m = 1e9+7;
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= target; j++) {
                for (int k = 1; k<=j && k<=f; k++) {
                    dp[i][j] = dp[i][j]%m + dp[i-1][j-k]%m;
                    dp[i][j] %= m;
                }
            }
        }
        return dp[d][target];
    }
};
