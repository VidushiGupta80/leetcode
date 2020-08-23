//Best Time to -> 08/23/2020 12:47
class Solution {
// int dp(int index, bool buy, vector<int>& prices, int& fee, map<pair<int,bool>, int>& cache)
//     {
//         if(index >= prices.size())
//             return 0;
//         if(cache.find(make_pair(index, buy)) != cache.end())
//             return cache[make_pair(index, buy)];
//         if(!buy)
//            {
//                int ans = 0;
//                 ans = max(ans, dp(index + 1, false, prices, fee, cache));
//                for(int i = index + 1; i < prices.size(); i++)
//                {
//                    ans = max(ans, dp(i, true, prices, fee, cache) - prices[index] - fee);
//                }
//                // ans -= fee;
//                return cache[make_pair(index, buy)] = ans;
//            }
//           else
//            {
//                int ans = prices[index] + dp(index + 1, false, prices, fee, cache);
//                return cache[make_pair(index, buy)] = ans;
//            }
        
//     }
public:
    int maxProfit(vector<int>& prices, int fee) {
        // map<pair<int, bool>, int> cache;
        // return dp(0, false, prices, fee, cache);
        int Buy = -prices[0]; 
        int Sell = 0; 
        
        for(int i=1; i<prices.size(); i++){
            int nbuy=max(Buy, Sell-prices[i]);
            int nsell=max(Sell, Buy +prices[i]-fee);
            
            Buy = nbuy; 
            Sell = nsell;
        }
        return Sell;
    }
};
