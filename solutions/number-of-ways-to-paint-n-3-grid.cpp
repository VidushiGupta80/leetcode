//Number of Ways to Paint N × -> 08/30/2020 19:46
class Solution {
public:
    int numOfWays(int n) {
        long long d = 6;
        long long s = 6;
        long long total = 12;
        const long long mod = 1e9+7;
        for(int i = 2; i <= n; i++)
        {
            long long sTemp = (3 * s + 2 * d) % mod;
            long long dTemp = (2 * s + 2 * d) % mod;
            total = (sTemp + dTemp) % mod;
            s = sTemp % mod;
            d = dTemp % mod;
        }
        return total;
    }
};
