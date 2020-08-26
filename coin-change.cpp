//Coin Change -> 08/26/2020 18:11
class Solution {
int dp(int sum, int amount, vector<int>& coins, unordered_map<int, int>& cache)
{
    if(sum == 0)
        return 0;
    if(cache.find(sum) != cache.end())
        return cache[sum];
    int ans = INT_MAX - amount;
    for(int i = 0; i < coins.size(); i++)
    {
        if(sum - coins[i] < 0)
            continue;
        ans = min(ans, 1 + dp(sum - coins[i], amount, coins, cache));
    }
    return cache[sum] = ans;
}
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> cache;
        sort(coins.begin(), coins.end(), greater<int>());
        int ans = dp(amount, amount, coins, cache);
        if(ans == INT_MAX - amount)
            return -1;
        return ans;
    }
};
