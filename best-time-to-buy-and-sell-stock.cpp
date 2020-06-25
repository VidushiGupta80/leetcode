//Best Time to Buy and Sell Stock</a -> 06/25/2020 15:29
class Solution {
private:
    int dp(int minBuy, int index, vector<int>& prices, map<pair<int, int>, int>& cache)
    {
        if(index >= prices.size())
            return 0;
        
        map<pair<int, int>, int> :: iterator it = cache.find(make_pair(minBuy, index));
        if(it != cache.end())
            return cache[make_pair(minBuy, index)];
        
        int ans = max((prices[index] - minBuy),
                      dp(min(prices[index], minBuy), index + 1, prices, cache));
        
        cache.insert(make_pair(make_pair(minBuy, index), ans));
        return ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        map<pair<int, int>, int> cache;
        int ans = dp(prices[0], 1, prices, cache);
        if(ans < 0)
            ans = 0;
        return ans;
    }
};
