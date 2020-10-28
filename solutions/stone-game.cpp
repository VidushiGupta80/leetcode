//Stone Game -> 06/25/2020 23:33
class Solution {
private:
    int dp(int start, int end, vector<int>& piles,map<pair<int, int>, int>& cache )
    {
        if(start > end)
            return 0;
        
        map<pair<int, int>, int> :: iterator it = cache.find(make_pair(start, end));
        if(it != cache.end())
            return cache[make_pair(start, end)];
        int mid =  dp(start + 1, end - 1, piles, cache);
        int first = piles[start] + max(dp(start + 2, end, piles, cache), mid);
        int last = piles[end] + max(dp(start, end - 2, piles, cache), mid);
        int ans = max(first, last);
        
        cache.insert(make_pair(make_pair(start, end), ans));
        return ans;
        
    }
    
public:
    bool stoneGame(vector<int>& piles) {
        return true;
        map<pair<int, int>, int> cache;
        int ans = dp(0, piles.size() - 1, piles, cache);
        int sum = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            sum += piles[i];
        }
        return ans > sum / 2;
    }
};
