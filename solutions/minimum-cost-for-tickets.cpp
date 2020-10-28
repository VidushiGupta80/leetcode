//Minimum Cost For Tickets -> 08/25/2020 22:03

class Solution {
private:
    int dp(int index, int covered, vector<int>& days, vector<int>& costs,
           map<pair<int, int>, int>& cache )
    {
        if(index >= days.size())
            return 0;
        
        map<pair<int, int>, int> :: iterator it = cache.find(make_pair(index, covered));
        if(it != cache.end())
            return cache[make_pair(index, covered)];
        
        int ans;
        if(days[index] < covered)
            ans = dp(index + 1, covered, days, costs, cache);
        else
        {
            int one = costs[0] + dp(index + 1, days[index] + 1, days, costs, cache);
            int seven = costs[1] + dp(index + 1, days[index] + 7, days, costs, cache);
            int thirty = costs[2] + dp(index + 1, days[index] + 30, days, costs, cache);
            ans = min(one, min(seven, thirty));
        }
        
        cache.insert(make_pair(make_pair(index, covered), ans));
        return ans;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<pair<int, int>, int> cache;
        int ans = dp(0, 0, days, costs, cache);
        return ans;
    }
};