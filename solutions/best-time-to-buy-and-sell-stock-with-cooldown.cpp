//Best Time to Buy and -> 06/25/2020 19:16
class Solution {
private:
    int dp(int index, bool buy,vector<int>& prices,map<pair<int, int>, int>& cache )
    {
        if(index >= prices.size())
            return 0;
        
        map<pair<int, int>, int> :: iterator it = 
            cache.find(make_pair(index, buy));
        
        if(it != cache.end())
            return cache[make_pair(index, buy)];
        
        int ans;
        if(buy)
        {
            ans = max(dp(index + 1, false, prices, cache) - prices[index],
                      dp(index + 1, true, prices, cache));
            cache.insert(make_pair(make_pair(index, buy), ans));
            
        }
        else if(!buy )
        {
            ans = max(prices[index] + dp(index + 2, true, prices, cache) , 
                      dp(index + 1, false, prices, cache)) ;
            cache.insert(make_pair(make_pair(index, buy), ans));
        }
        // else
        // {
        //     ans = dp(index + 1, buy, cooldown, prices, cache);
        // }
        return ans;
    }

public:
    int maxProfit(vector<int>& prices) {
        map<pair<int, int>, int > cache;
        int ans = dp(0, true, prices, cache);
        return ans;
    }
};
